#include <iostream>
using namespace std;
struct Node {
int data;
Node* left;
Node* right;
};
Node* newNode(int data) {
Node* node = new Node();
node->data = data;
node->left = node->right = NULL;
return node;
}
int countFullNodes(Node* root) {
if (root == NULL) return 0;
int count = countFullNodes(root->left) + countFullNodes(root->right);
if (root->left != NULL && root->right != NULL) count++;
return count;
}
int main() {
Node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);

root->right->right = newNode(5);

cout << "Full Nodes: " << countFullNodes(root) << endl;
return 0;
}