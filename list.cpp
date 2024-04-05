#include "list.hpp"
#include "dynamic.hpp"

List::List() {
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

List::~List() {
	this->ClearList();
}

void List::ClearList() {
	Node* current = head;

	while(current != NULL) {
		Node* temp = current;
		current = current->next;

		delete temp;
	}

	this->count = 0;
	this->head = NULL;
	this->tail = NULL;
}

void List::Remove(int index) {
	if (index < 0 || index > this->count) {
		return;
	}

	if (this->head == NULL) {
		return;
	}

	if (index == 0) {
		Node* current = this->head;
		this->head = this->head->next;

		delete current;
		this->count--;
		return;
	}

	Node* before = head;

	for(int i = 0; i < index - 1; i++) {
		before = before->next;
	}

	Node* current = before->next;

	Node* after = current->next;

	before->next = after;

	current->next = NULL;

	delete current;

	this->count--;
}

Dynamic* List::Get(int index) {
	if (this->head == NULL) {
		return NULL;
	}

	return this->head->Get();
}

int List::Length() {
	return this->count;
}

void List::Print() {
	Node* list = head;

	std::cout << "[";

	while(list != NULL) {
		list->Get()->Print();

		if (list->next != NULL) {
			std::cout << ", ";
		}

		list = list->next;
	}

	std::cout << "]\n";
}

void List::Push(bool val) {
	if (this->head == NULL) {
		this->head = new Node(val);
		this->tail = this->head;
		this->count++;

		return;
	}

	this->tail->next = new Node(val);
	this->tail = this->tail->next;
	this->count++;
}

void List::Push(int val) {
	if (this->head == NULL) {
		this->head = new Node(val);
		this->tail = this->head;
		this->count++;

		return;
	}

	this->tail->next = new Node(val);
	this->tail = this->tail->next;
	this->count++;
}

void List::Push(double val) {
	if (this->head == NULL) {
		this->head = new Node(val);
		this->tail = this->head;
		this->count++;

		return;
	}

	this->tail->next = new Node(val);
	this->tail = this->tail->next;
	this->count++;
}

void List::Push(const char* val) {
	if (this->head == NULL) {
		this->head = new Node(val);
		this->tail = this->head;
		this->count++;

		return;
	}

	this->tail->next = new Node(val);
	this->tail = this->tail->next;
	this->count++;
}

void List::Push(Dynamic val) {
	if (this->head == NULL) {
		this->head = new Node(val);
		this->tail = this->head;
		this->count++;

		return;
	}

	this->tail->next = new Node(val);
	this->tail = this->tail->next;
	this->count++;
}
