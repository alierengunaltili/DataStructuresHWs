#include "StrangeCalculator.h"
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

StrangeCalculator::StrangeCalculator() {
	topPtr = NULL;
}


bool StrangeCalculator::isEmpty() const {
	return (topPtr == NULL);
}


bool StrangeCalculator::getTop(char& stackTop) const {
	if (isEmpty()) {
		//cout << "Empty stack " << endl;
		return false;
	}
	else {
		stackTop = topPtr->item;
		return true;
	}
}

bool StrangeCalculator::pop(char& stackTop) {
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

string StrangeCalculator::reverse(const string str) {
	int size = str.length();
	return " ";
}

char StrangeCalculator::top() {
	if (isEmpty()) {
		return ' ';
	}
	else {
		char ch = topPtr->item;
		return ch;
	}
}



bool isBalancedInfix(const string exp) {
	bool flag = true;
	StrangeCalculator s;

	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '(') {
			s.push(exp[i]);
		}
		else if (exp[i] == ')') {
			if (s.isEmpty()) {
				return false;
			}
			s.pop();
		}
	}

	if (s.isEmpty()) {
		return true;
	}
	else {
		return false;
	}
}

void evaluateInputPrefixExpression() {
	string tmp;
	cout << "Type infix input " << endl;
	getline(cin, tmp);
	int j = 0;
	int size = 0;
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] != ' ') {
			size++;
		}
	}
	char* extracted = new char[size];

	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] != ' ') {
			extracted[j] = tmp[i];
			j++;
		}
	}

	string tmp2;
	for (int i = 0; i < size; i++) {
		tmp2 += extracted[i];
	}
	//cout << endl;
	bool flag = isBalancedInfix(extracted);
	if (flag) {
		string res = infix2prefix(tmp2);
		cout << "Prefix of " << tmp2 << " is: " << res << endl;
		cout << "The result of prefix is: " << evaluatePrefix(res) << endl;
	}
	else {
		cout << "Inbalanced parantheses, no operation can done. " << endl;
	}
	delete[] extracted;
}

double evaluatePrefix(const string exp) {
	int size = exp.length();
	char* arr = new char[size];

	for (int i = 0; i < size; i++) {
		arr[i] = exp[size - i - 1];
	}

	IntStack st;
	// number between 1 and 9 can be checked with ascii value between 48 and 58.
	for (int i = 0; i < size; i++) {
		if (arr[i] < 58 && arr[i] > 48) {
			int x = (int)arr[i];
			double d = x - 48;
			st.push(d);
		}
		else {
			if (!st.isEmpty()) {
				int max = 214748647;
				double n1, res;
				double n2;
				n2 = max;
				st.pop(n1);
				if (!st.isEmpty()) {
					st.pop(n2);
				}
				if (n2 != max) {
					if (arr[i] == '*') {
						res = n1 * n2;
					}
					else if (arr[i] == '/') {
						res = n1 / n2;
					}
					else if (arr[i] == '+') {
						res = n1 + n2;
					}
					else if (arr[i] == '-') {
						res = n1 - n2;
					}
					st.push(res);
				}
			}
		}
	}
	double result;
	st.pop(result);
	delete[] arr;
	arr = NULL;
	return result;
}

string infix2prefix(const string exp) {
	string str1 = '(' + exp +')';

	int size = str1.length();
	char ch = str1[size - 1];
	char* arr = new char[size];
	
	for (int i = 0; i < size; i++) {
		arr[i] = str1[size - i - 1];
	}

	StrangeCalculator result, s;
	for (int i = 0; i < size; i++) {
		if (arr[i] == ')') {
			s.push(arr[i]);
		}
		else if (arr[i] > 48 && arr[i] < 58) {
			result.push(arr[i]);
		}
		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '/' || arr[i] == '*') {
			if (s.isEmpty()) {
				s.push(arr[i]);
			}
			else {
				if (s.precedence(arr[i]) > s.precedence(s.top()) ) {
					s.push(arr[i]);
				}
				else if (s.precedence(arr[i]) == s.precedence(s.top())) {
					s.push(arr[i]);
				}
				else {
					while  ( (!s.isEmpty()) && (s.precedence(arr[i]) < s.precedence(s.top()) ) ) {
						char t;
						s.pop(t);
						result.push(t);
					}
					s.push(arr[i]);
				}
			}
		}
		else if (arr[i] == '(') {
			char tmp = 'X';
			while (tmp != ')' && !s.isEmpty()) {
				s.pop(tmp);
				if (tmp != ')') {
					result.push(tmp);
				}
			}
			//s.pop();
		}
	}

	delete[] arr;
	arr = NULL;
	char ch3;
	string res = "";
	while ((!result.isEmpty())) {
		result.pop(ch3);
		res += ch3;
	}
	return res;
}


int StrangeCalculator::precedence(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	if (c == '/' || c == '*') {
		return 2;
	}
	return 0;
}
bool StrangeCalculator::push(char nItem) {
	StackNode* newTop = new StackNode;
	newTop->item = nItem;
	newTop->next = topPtr;
	topPtr = newTop;
	return true;
}

bool StrangeCalculator::pop() {
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

StrangeCalculator::~StrangeCalculator() {
	//cout << "DEST " << endl;
	while (!isEmpty()) {
		pop();
	}
}

StrangeCalculator::StrangeCalculator(const StrangeCalculator& aStack) {
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



//Stack(const Stack& aStack);
//~Stack();

