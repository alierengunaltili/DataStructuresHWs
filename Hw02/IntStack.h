#include <iostream>
#include <string>
using namespace std;

#pragma once 
class IntStack
{
public:
    IntStack();
    IntStack(const IntStack& aStack);
    ~IntStack();

    bool isEmpty() const;
    bool push(double newItem);
    bool pop();
    bool pop(double& stackTop);
    bool getTop(double& stackTop) const;

private:
    struct StackNode {            // a node on the stack
        double item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };
    StackNode* topPtr;     // pointer to first node in the stack
};

