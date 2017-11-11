#include "../include/Queue.h"

#include <cstddef>
#include <iostream>

Queue::Queue() {
    this->firstNode = this->lastNode = NULL;
    this->size = 0;
}

Queue::~Queue() {
    QueueNode* tmpQueueNode = this->firstNode;
    QueueNode* currentQueueNode = NULL;
    while(tmpQueueNode != NULL) {
        currentQueueNode = tmpQueueNode;
        tmpQueueNode = tmpQueueNode->next;
        delete currentQueueNode;
    }
    delete tmpQueueNode;
    delete[] this;
}

QueueNode::QueueNode(int value) {
    this->previus = this->next = NULL;
    this->content = value;
}

QueueNode::~QueueNode() {
}

inline bool Queue::isEmpty() {
    return (this->firstNode == NULL);
}

void Queue::enqueue(int value) {
    if(!isEmpty()) {
        this->lastNode->previus = new QueueNode(value);
        this->lastNode->previus->next = this->lastNode;
        this->lastNode = this->lastNode->previus;
        this->size++;
    }else {
        this->firstNode = this->lastNode = new QueueNode(value);
        this->size++;
    }
}

int Queue::dequeue() {
    if(!isEmpty()) {
        QueueNode *tmpNode = this->firstNode;
        int value = tmpNode->content;
        if(this->firstNode != this->lastNode) {
            this->firstNode = this->firstNode->previus;
            this->firstNode->next = NULL;
            delete tmpNode;
        }
        this->size--;
        return value;
    }else {
        return -1;
    }
}

inline int Queue::getSize() {
    return (this->size);
}