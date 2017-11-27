#ifndef STACK_DATA_STRUCT_H
#define STACK_DATA_STRUCT_H 1

class StackNode {
    friend class Stack;

    public:
        StackNode(int);
        ~StackNode();
        inline int getContent();
    
    private:
        StackNode* nextNode;
        int content;
};

class Stack {
    public:
        Stack();
        ~Stack();
        void push(int);
        int pop();
        inline int getSize();
        inline bool isEmpty();
    private:
        StackNode* top;
        int size;
};

#endif