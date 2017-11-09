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
 * This file contains the Linked List data structure implementation
 * with all methods, constructor and object destructor.
 */
#include "../include/LinkedList.h"

#include <cstddef>

/**
 * \brief LinkedList constructor.
 * 
 * This is the linked list object constructor.
 * It sets the first and last element attribute state
 * as NULL and lastSize as 0.
 */
LinkedList::LinkedList() {
    this->firstElement = this->lastElement = NULL;
    this->listSize = 0;
}

/**
 * \brief LinkedList destructor.
 * 
 */
LinkedList::~LinkedList() {

}

/**
 * \brief Node object constructor overwrited.
 * 
 * This constructor sets the nextNode attribute state pointer
 * as NULL and node content as 0.
 * 
 * \param value A integer node content value.
 */
Node::Node(int value) {
    this->nextNode = NULL;
    this->content = value;
}

/**
 * \brief Node object constructor overwrited.
 * 
 * This constructor sets the nextNode attribute state
 * pointer as NULL and node content as 0.
 */
Node::Node() {
    this->nextNode = NULL;
    this->content = 0;
}

/**
 * \brief Node object destructor.
 * 
 */
Node::~Node() {

}

/**
 * \brief isEmpty method.
 * 
 * This method verifys if the linked list is empyt.
 * If yes, returns true., verifing if the first element 
 * attribute state pointer is NULL.
 * 
 * \return true If the linked list is empty.
 * \return false If the linked list isn't empty.
 */
inline bool LinkedList::isEmpty() {
    return this->firstElement == NULL;
}

/**
 * \brief size method.
 * 
 * This method returns for the caller method the linked
 * list size or linked list node amount.
 * 
 * \return int The linked list integer size value.
 */
inline int LinkedList::size() {
    return this->listSize;
}

/**
 * \brief add Method.
 * 
 * This method adds a value to node content.
 * 
 * \param value The integer value to add on node content.
 */
void LinkedList::add(int value) {
    if(!isEmpty()) {
        Node *tmpNode = this->firstElement;
        while(tmpNode->nextNode != NULL) {
            tmpNode = tmpNode->nextNode;
        }
        tmpNode->nextNode = new Node(value);
    }else {
        this->lastElement = this->firstElement = new Node(value);
    }
    this->listSize++;
}

/**
 * \brief remove method.
 * 
 * This method removes a specifc value of linekd list.
 * 
 * \param value A value that user wants to remove.
 */
void LinkedList::remove(int value) {
    if(!isEmpty()) {
        Node *tmpNode = this->firstElement;
        this->firstElement = this->firstElement->nextNode;
        tmpNode->nextNode = NULL;
        delete tmpNode;
        this->listSize--;
    }
}

/**
 * \brief get method.
 * 
 * This method localizes a specific node by index value received
 * by parameter.
 * 
 * \param index A integer index to localize the specific node.
 * \return int The node content integer value.
 */
int LinkedList::get(int index) {
    if(!isEmpty()) {
        if(index != this->listSize) {
            Node *tmpNode = this->firstElement;
            for(int i=0; i < index; i++) {
                tmpNode = tmpNode->nextNode;
            }
            return tmpNode->getElement();
        }else {
            return this->lastElement->getElement();
        }
    }else {
        return -1;
    }
}

/**
 * \brief getElement method.
 * 
 * It is an accessor method for getting the node content.
 * 
 * \return int The integer node content value.
 */
inline int Node::getElement() {
    return this->content;
}

