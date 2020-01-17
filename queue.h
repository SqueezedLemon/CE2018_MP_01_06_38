#include <iostream>

class Node{
public:
    char info;
    Node *next;
};

class Queue{
private:
    Node *HEAD;
    Node *TAIL;
public:
    Queue();
    ~Queue();

    bool isEmpty();             //checks if the queue is empty
    void enqueue(char data);    //adds elements into the queue
    char dequeue();             //removes elemets from the queue
    char front();           //returns the elements at the front
    char rear();            //returns the element at the rear
    void traverse();            //returns all element of the queue
    void checkEmpty();          //to display text message during output
};
