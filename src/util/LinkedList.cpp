/**
 * \file LinkedList.cpp
 * \date 08/11/2017
 * \author Lucas Fonseca dos Santos
 * \copyright GNU-3 Public License.
 * 
 * \section FILE DOCUMENTATION
 * 
 * FEDERAL UNIVERSITY OF LAVRAS - Algorithms in Graphs Discipline
 * PROFESSOR: MAYRON MOREIRA.
 * TOUR GUIDE PROBLEM SOLUTION SOFTWARE.
 * WRITTEN BY: LUCAS FONSECA DOS SANTOS (201712078).
 * 
 * This files describes the graph data structure implementation 
 * with the object constructors and all methods implementation.
 */
#include "../include/LinkedList.h"

#include <cstddef>

LinkedList::LinkedList() {
    this->firstElement = this->lastElement = NULL;
    this->listSize = 0;
}

LinkedList::~LinkedList() {

}

Node::Node(int value) {
    this->nextNode = NULL;
    this->content = value;
}

Node::Node() {
    this->nextNode = NULL;
    this->content = 0;
}

Node::~Node() {

}

inline bool LinkedList::isEmpty() {
    return this->firstElement == NULL;
}

inline int LinkedList::size() {
    return this->listSize;
}

void LinkedList::add(int value) {
    if(!isEmpty()) {
        Node* tmpNode = this->firstElement;
        while(tmpNode->nextNode != NULL) {
            tmpNode = tmpNode->nextNode;
        }
        tmpNode->nextNode = new Node(value);
    }else {
        this->lastElement = this->firstElement = new Node(value);
    }
    this->listSize++;
}

void LinkedList::remove(int value) {
    if(!isEmpty()) {
        Node* tmpNode = this->firstElement;
        this->firstElement = this->firstElement->nextNode;
        tmpNode->nextNode = NULL;
        delete tmpNode;
        this->listSize--;
    }
}

