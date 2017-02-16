/*
 * This library contain
 * * Push()
 * * Pop()
 * * Top()
 * * Size()
 * * Empty()
 * * reverse()
 * Created by Asif Raza on 16/02/2017.
 */


#ifndef CPP_DATASTRUCTURES_STACK_H
#define CPP_DATASTRUCTURES_STACK_H

#include <MacTypes.h>       // For NULL
#include <iostream>         // For std::

#define STACK_INIT_SIZE 0


template <typename T>
class mStack {

    struct Node{
        T data;     // data store
        Node *next; // point next
    };

private:
    Node *head;     // follow top

public:
    mStack(){
        head = NULL;
    };

    void push(T data){
        Node *q = new Node;
        q->data = data;
        q->next = head;
        head = q;
    };

    void pop(){
        if(head==NULL) std::cout << "Stack is empty.\n";

        else{
            Node *q = head;
            head = head->next;
            delete q;
        }
    };

    T top(){
        Node *q = head;
        return q->data;
    }

    void display(){
        Node *q = head;

        while (q) {
            std::cout << q->data << " ,";
            q = q->next;
        }
    }

    unsigned long int size(){
        Node *q = head;
        unsigned long int return_size = STACK_INIT_SIZE;        // clear the garbig
        while (q!=NULL) {
            q = q->next;
            return_size++;
        }
        return return_size;
    };

    void empty(){
        while (head!=NULL) {
            Node *q = head;
            head = head->next;
            delete q;
        }
    }

    void reverse(){
        Node *p = new Node;
        Node *current = head;
        while (current!=NULL) {
            p->data = current->data;
            p->next = current->next;
            current = current->next;
        }
        current = head;
        while (p != NULL) {
            current->data = p->data;
            p = p->next;
            current = current->next;
        }
    }

};  // End_Of_Class


#endif //CPP_DATASTRUCTURES_STACK_H
