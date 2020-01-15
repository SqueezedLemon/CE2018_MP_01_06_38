#include <iostream>
#include "queue.h"
#define MAX 5

using std :: cout;
using std :: endl;

int count = 0;

Queue :: Queue(){
    HEAD = NULL;
    TAIL = NULL;
}

Queue :: ~Queue(){}

bool Queue :: isEmpty(){
    return (HEAD == NULL);
}

void Queue::checkEmpty(){
	if (isEmpty())
		cout<<"The Queue is empty."<<endl;
	else
		cout<<"The Queue is not empty."<<endl;
}

void Queue :: enqueue(char data){
    if (count == MAX){
        cout << "Queue Overflow!" << endl;
    }
    else{
        Node *newNode = new Node();
        newNode -> info = data;
        newNode -> next = NULL;
        if(isEmpty()){
            TAIL = newNode;         //for addition of the first element.
            HEAD = TAIL;
            TAIL->next = HEAD;
        }
        else{
            TAIL -> next = newNode;
            TAIL = newNode;
            TAIL->next=HEAD;
        }
        count++;
    }
}

char Queue :: dequeue(){
    if (isEmpty()){
        cout << "Queue Underflow!" << endl;
        return '-';
    }
    else{
        Node *toDelete;
        char value;
        toDelete = HEAD;
        value = toDelete -> info;
        HEAD = toDelete -> next;
        delete toDelete;
        count--;
        TAIL->next=HEAD;
        return value;
    }

}

char Queue :: peekFront(){
    if (isEmpty()){
        cout << "Queue Underflow!" <<endl;
        return '-';
    }
    else{
        return (HEAD -> info);
    }
}

char Queue :: peekRear(){
    if (isEmpty()){
        cout << "Queue Overflow!" << endl;
        return '-';
    }
    else{
        return (TAIL -> info);
    }
}

void Queue :: traverse(){
    Node *temp = HEAD;
    while (temp->next != HEAD){
        cout << temp -> info <<endl;
        temp = temp -> next;
    }
    cout << temp->info <<endl;
}


int main(){
    Queue Q;
    Q.checkEmpty();
    cout << "-----------------------------" << endl;
    Q.dequeue();
    Q.enqueue('a');
    Q.enqueue('p');
    Q.enqueue('p');
    Q.enqueue('l');
    Q.enqueue('e');
    Q.enqueue('B');
    Q.traverse();
    cout << "-----------------------------" << endl;
    cout << Q.peekFront() << endl;
    cout << Q.peekRear() << endl;
    cout << "-----------------------------" << endl;
    Q.dequeue();
    Q.dequeue();
    Q.enqueue('m');
    Q.enqueue('n');
    Q.enqueue('o');
    Q.traverse();
    cout << "-----------------------------" << endl;
    Q.checkEmpty();
    return 0;
}
