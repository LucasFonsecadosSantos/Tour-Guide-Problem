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

class LinkedList {

    public:
        LinkedList();
        ~LinkedList();
        void add(int);
        void remove(int);
        inline int size();
        int get(int);
    
    private:
        Node* firstElement;
        Node* lastElement;
        int listSize;
        inline bool isEmpty();
};

#endif