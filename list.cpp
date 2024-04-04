#include "list.hpp"
#include "dynamic.hpp"

List::List() {
	this->next = NULL;
	this->value = NULL;
}

List::~List() {
	this->ClearList();
}

void List::ClearList() {
	if (this->next != NULL) {
		this->next->ClearList();

		delete this->next;
	}

	if (this->value != NULL) {
		delete this->value;
	}

	this->value = NULL;

	this->next = NULL;
}

void List::Remove(int index) {
	List* before = this;

	if (index == 0) {
		*this = *this->next;

		before->next = NULL;

		delete before;

		return;
	}

	for(int i = 0; i < index - 1; i++) {
		if (before == NULL || before->value == NULL) {
			return;
		}

		before = before->next;
	}

	List* after = (before->next != NULL) ? before->next->next : NULL;

	List* deletion = before->next;

	if (deletion == NULL) {
		return;
	}

	before->next = after;

	deletion->next = NULL;

	delete deletion;
}

Dynamic* List::Get(int index) {
	return this->value;
}

int List::Length() {
	List* list = this;
	int counter = 0;

	while(list->value != NULL) {
		counter++;
		list = list->next;
	}

	return counter;
}

void List::Print() {
	List* list = this;

	std::cout << "[";

	while(list->value != NULL) {
		list->value->Print();

		if (list->next->value != NULL) {
			std::cout << ", ";
		}

		list = list->next;
	}

	std::cout << "]\n";
}

List* List::GetLastNode() {
	List* list = this;

	while(list->next != NULL) {
		list = list->next;
	}

	return list;
}

void List::Add(const bool val) {
	List* last = this->GetLastNode();

	last->value = new Dynamic(val);
	last->next = new List();
}

void List::Add(const int val) {
	List* last = this->GetLastNode();

	last->value = new Dynamic(val);
	last->next = new List();
}

void List::Add(const double val) {
	List* last = this->GetLastNode();

	last->value = new Dynamic(val);
	last->next = new List();
}

void List::Add(const char* val) {
	List* last = this->GetLastNode();

	last->value = new Dynamic(val);
	last->next = new List();
}

void List::Add(Dynamic val) {
	List* last = this->GetLastNode();

	last->value = new Dynamic(val);

	last->next = new List();
}
