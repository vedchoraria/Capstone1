#include<iostream>
using namespace std;
#include<queue>

class TreeNode{
    public:
    int data;
    TreeNode* left,* right;
    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }

};

TreeNode* createBinaryTree(){
    
    int val;
    cout<<"(-1 for no node): ";
    cin>>val;
    if(val == -1) return nullptr; 
    TreeNode* root = new TreeNode(val);
    cout<<"Enter left child of "<<val<<": ";
    root->left = createBinaryTree();

    cout<<"Enter right child of "<<val<<": ";
    root->right = createBinaryTree();
    return root;

}

void inorderTraversal(TreeNode*root){
    if(root == nullptr) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode*root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode*root){
    if(root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

void LevelOrderTraversal(TreeNode* root){
    if(root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!= nullptr) q.push(curr->left);
        if(curr->right != nullptr) q.push(curr->right);
    }

}
int main(){
    TreeNode *root = createBinaryTree();
    cout<<"INORDER TRAVERSAL: ";
    inorderTraversal(root);
    cout<<endl;
    cout<<"PREORDER TRAVERSAL: ";
    preorderTraversal(root);
    cout<<endl;
    cout<<"POSTORDER TRAVERSAL: ";
    postorderTraversal(root);
    cout<<endl;
    cout<<"LEVEL ORDER TRAVERSAL: ";
    LevelOrderTraversal(root);
    cout<<endl;
    return 0;
    // delete root; // Free the memory allocated 

}

