/**
 * \file LinkedList.h
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
#ifndef LINKED_LIST_DATA_STRUCTURE_H
#define LINKED_LIST_DATA_STRUCTURE_H 1

/**
 * \class LinkedList
 * 
 * \section CLASS DOCUMENTATION
 * 
 * 
 */
class Node {
    
    friend class LinkedList;

    public:
        Node();
        Node(int);
        ~Node();
        inline int getElement();
        void addElement();
    
    private:
        int content;
        Node* nextNode;
};

/**
 * \class LinkedList
 * 
 * This class describes the LinkedList data structure.
 * It is util for manipuling and transfer between methods
 * in the main algorithm.
 */
class LinkedList {

    public:

        /**
         * \brief LinkedList constructor.
         * 
         * The linked list data structure constructor
         * prototype.
         */
        LinkedList();

        /**
         * \brief LinkedList destructor.
         * 
         * The linked list data structure destructor
         * prototype.
         */
        ~LinkedList();

        /**
         * \brief add method.
         * 
         * A adder linked list method prototype.
         * 
         * \param int A integer value to add on linked list.
         */
        void add(int);

        /**
         * \brief remove method.
         * 
         * A linked list remove method prototype.
         * 
         * \param A integer value to remove of linked list.
         */
        void remove(int);
        
        /**
         * \brief size method.
         * 
         * A size method getter of linked list data structure
         * prototype.
         * 
         * \return int A integer value of linked list size.
         */
        inline int size();
        
        /**
         * \brief get method.
         * 
         * The accessor value method at position on linked
         * list data structure prototype.
         * 
         * \param A integer index of position value.
         * \return int A integer node content.
         */
        int get(int);
    
    private:

        /**
         * \var firstElement
         * 
         * This attribute represents the first 
         * Linked List structure node pointer.
         */
        Node* firstElement;

        /**
         * \var lastElement 
         * 
         * This attribute represents the last linked
         * list element structure node pointer.
         */
        Node* lastElement;

        /**
         * \var listSize
         * 
         * This attribute represents the linked list
         * size value. It is the list node amount and also
         * is used for representing the position index node-
         * -per-node.
         */
        int listSize;

        /**
         * \brief isEmpty method.
         * 
         * This method verifys if the linked list are empty. It checks if
         * the first element pointer attribute state is NULL.
         * 
         * \return true If the linked list is empty.
         * \return false If the linked list isn't empty.
         */
        inline bool isEmpty();
};

#endif