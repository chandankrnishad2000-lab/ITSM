#include <iostream>
using namespace std;
 class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void postorder(Node* root){
    if(root == NULL){
        return; 

 }      
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main(){
    Node* root = new Node(10);      
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    cout << "Postorder Traversal: ";
    postorder(root);
    return 0;
}