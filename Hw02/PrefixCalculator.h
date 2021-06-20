#include <iostream>
#include <string>
#include "IntStack.h"
using namespace std;

double evaluatePrefix(const string exp);
string infix2prefix(const string exp);
bool isBalancedInfix(const string exp);
void evaluateInputPrefixExpression();

#pragma once 
class StrangeCalculator
{
public:
    StrangeCalculator();
    StrangeCalculator(const StrangeCalculator& aStack);
    ~StrangeCalculator();

    bool isEmpty() const;
    bool push(char newItem);
    bool pop();
    bool pop(char& stackTop);
    bool getTop(char& stackTop) const;
    char top();
    int precedence(char c);

private:
    struct StackNode {            // a node on the stack
        char item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };

    string reverse(const string str);
    StackNode* topPtr;     // pointer to first node in the stack
};

