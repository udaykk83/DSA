#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* createNode(int data){
    TreeNode* nn=new TreeNode();
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
void preOrder(TreeNode* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(TreeNode* root){
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(TreeNode* root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    TreeNode* root =createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    
    cout<<"Pre Order  ";
    preOrder(root);
    cout<<endl;
    cout<<"In Order   ";
    inOrder(root);
    cout<<endl;
    cout<<"Post Order ";
    postOrder(root);
    return 0;
}
