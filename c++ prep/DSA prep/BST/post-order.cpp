#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int x) {
        data = x;
        left = right = NULL;    

    }
};
void postOrder(node* root) {
    if (root == NULL) {
        return;     
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";          
}
int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);          
    root->left->left = new node(4);
    postOrder(root);
    return 0;
}
