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
void insertAtposition(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    if(position == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for(int i=1; i<position-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Position out of bounds" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int main(){
    Node* head = NULL;
    insertAtposition(head, 10, 1);      
    insertAtposition(head, 20, 2);
    insertAtposition(head, 30, 3);
    insertAtposition(head, 40, 2); // Inserting at position 2
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
