#include "../include/Queue.h"

#include <cstddef>

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
    this->previus = this->next = NULL;
    delete[] this;
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
        QueueNode* targetQueueNode = this->firstNode;
        this->firstNode = this->firstNode->previus;
        this->firstNode->next = NULL;
        this->size--;
        int value = targetQueueNode->content;
        delete targetQueueNode;
        return value;
    }else {
        return -1;
    }
}

inline int Queue::getSize() {
    return (this->size);
}