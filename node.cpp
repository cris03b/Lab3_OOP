#include "node.h"
#define NULL 0;

Node::Node() {
	this->ln = NULL;
	this->rn = NULL;
	this->val = 0;
}

Node::~Node() {
	delete this->ln;
	delete this->rn;
}