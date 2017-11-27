#include "../../include/Stack.h"

#include <cstddef>

Stack::Stack() {
    this->size = 0;
    this->top = NULL;
}

Stack::~Stack() {

}

StackNode::StackNode(int value) {
    this->nextNode = NULL;
    this->content = value;
}

StackNode::~StackNode() {

}

inline int StackNode::getContent() {
    return this->content;
}

inline int Stack::getSize() {
    return this->size;
}

inline bool Stack::isEmpty() {
    return (this->top == NULL);
}

void Stack::push(int value) {
    if(!isEmpty()) {
        StackNode* tmpNode = new StackNode(value);
        tmpNode->nextNode = this->top;
        this->top = tmpNode;
        this->size++;
    }else {
        this->top = new StackNode(value);
        this->size++;
    }
}

int Stack::pop() {
    if(!isEmpty()) {
        int value = this->top->getContent();
        StackNode* tmpNode = this->top;
        this->top = this->top->nextNode;
        delete tmpNode;
        return value;
    }else {
        return -1;
    }
}