#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;

    node(int x) {
        data = x;
        left = NULL;
    }
};
void inOrder(node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
}
int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->left->left = new node(4);
    inOrder(root);
    return 0;
}