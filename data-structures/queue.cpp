#include <bits/stdc++.h>

typedef struct Node {
    int val;
    Node *next;

    Node(){
        this->next = NULL;
        this->val = -1;
    }
};

class Queue {
    int size;
    Node *head, *tail;

    public:
    Queue (){
        this->size = 0;
        this->head = this->tail = new Node();
    }

    void insert(int newVal){
        // creating new node
        Node *n = new Node();
        n->val = newVal;
        n->next = this->tail->next;

        // inserting new node at the end of the queue
        this->tail->next = n;
        this->tail = n;
        
        // updating queues size
        this->size++;
    }

    void pop(){
        // if the queue is empty => cant pop
        if (this->size == 0) return; 

        // removing element from front
        Node *del = this->head->next;
        this->head->next = del->next;
        this->size--;

        // if the queue is empty
        if (this->size == 0) this->tail = this->head;
    }

    int size(){
        return this->size;
    }
};