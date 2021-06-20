#include "IntStack.h"


IntStack::IntStack() {
	topPtr = NULL;
}


bool IntStack::isEmpty() const {
	return (topPtr == NULL);
}


bool IntStack::getTop(double& stackTop) const {
	if (isEmpty()) {
		return false;
	}
	else {
		stackTop = topPtr->item;
		return true;
	}
}

bool IntStack::pop(double& stackTop) {
	if (isEmpty()) {
		return false;
	}
	else {
		stackTop = topPtr->item;
		StackNode* tmp = topPtr;
		topPtr = topPtr->next;
		tmp->next = NULL;
		delete tmp;
		return true;
	}
}


bool IntStack::push(double nItem) {
	StackNode* newTop = new StackNode;
	newTop->item = nItem;
	newTop->next = topPtr;
	topPtr = newTop;
	return true;
}

bool IntStack::pop() {
	if (isEmpty()) {
		return false;
	}
	else {
		StackNode* head = topPtr;
		topPtr = topPtr->next;
		head->next = NULL;
		delete head;
		return true;
	}
}

IntStack::~IntStack() {
	while (!isEmpty()) {
		pop();
	}
}

IntStack::IntStack(const IntStack& aStack) {
	if (aStack.isEmpty()) {
		topPtr = NULL;
	}
	else {
		topPtr = new StackNode;
		topPtr->item = aStack.topPtr->item;
		StackNode* newptr = aStack.topPtr;

		for (StackNode* tmp = aStack.topPtr->next;
			tmp != NULL;
			tmp = tmp->next) {
			newptr->next = new StackNode;
			newptr = newptr->next;
			newptr->item = tmp->item;
		}
		newptr->next = NULL;
	}
}
