#include <iostream>
using namespace std;

class StackLL {
    private:
    class Node {
        public:
        int data;
        Node* next;

        Node (int val){
            data = val;
            next = NULL;
        }
    };
public:
    Node* top;

    StackLL(){
        top = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(top == NULL){
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(top == NULL){
            cout<<"Stack underflow"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if(top == NULL){
            cout<<"Stack is empty"<<endl;
            return -1; 
        }
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
};