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
void insertAtbeginning(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
    int main(){
        Node* head = NULL;
        insertAtbeginning(head, 10);
        insertAtbeginning(head, 20);
        insertAtbeginning(head, 30);

        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        return 0;
}