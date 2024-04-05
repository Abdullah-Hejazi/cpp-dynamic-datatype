#include "node.hpp"

Node::Node(bool val) {
	this->value = new Dynamic(val);
	this->next = NULL;
}

Node::Node(int val) {
	this->value = new Dynamic(val);
	this->next = NULL;
}

Node::Node(double val) {
	this->value = new Dynamic(val);
	this->next = NULL;
}

Node::Node(const char* val) {
	this->value = new Dynamic(val);
	this->next = NULL;
}

Node::Node(Dynamic val) {
	this->value = new Dynamic(val);
	this->next = NULL;
}

Node::~Node() {
	if (this->value == NULL) {
		return;
	}
	delete this->value;
}

Dynamic* Node::Get() {
	return this->value;
}