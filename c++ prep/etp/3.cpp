#include <iostream>
using namespace std;
 class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void insertAtend(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return; 
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

        int main(){
            Node* head = NULL;
            insertAtend(head, 10);
            insertAtend(head, 20);
            insertAtend(head, 30);

            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            return 0;   
 }