#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* createNode(int key){
    TreeNode* nn=new TreeNode();
    nn->data=key;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

void preorder(TreeNode* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);    
    preorder(root->right);
}

int convertToSumTree(TreeNode* root){
    if(root == NULL)
        return 0;
    int lstSum = convertToSumTree(root->left);
    int rstSum = convertToSumTree(root->right);
    int rootValue = root->data;
    root->data = lstSum + rstSum;
    return lstSum + rstSum + rootValue;
}
    

int main(){
    TreeNode* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->left->left->left=createNode(6);
    preorder(root);
    cout<<endl;
    int dummy = convertToSumTree(root);
    
    preorder(root);
    return 0;
}