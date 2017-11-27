#ifndef QUEUE_DATA_STRUCTURE_H
#define QUEUE_DATA_STRUCTURE_H 1

class QueueNode {
    friend class Queue;

    public:
        QueueNode(int);
        ~QueueNode();
    private:
        int content;
        QueueNode* next;
        QueueNode* previus;
};

class Queue {
    
        public:
            Queue();
            ~Queue();
            void enqueue(int);
            int dequeue();
            inline int getSize();
        private:
            int size;
            inline bool isEmpty();
            QueueNode* firstNode;
            QueueNode* lastNode;
    
    };

    


#endif