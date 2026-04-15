#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node (int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

int main (){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    second-> prev = head;
    third-> prev = second;
    fourth-> prev = third;   
    fifth-> prev = fourth;

    cout << "Forward Traversal: ";
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " <->";  
        temp = temp->next;

}

cout << "NULL/n";

cout << "Backward Traversal: ";
temp = fifth;
while(temp != NULL){
    cout << temp->data << " <->";
    temp = temp-> prev;
}
cout << "NULL/n";
return 0;
}
