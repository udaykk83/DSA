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
    
    preorder(root->left);  
    cout<<root->data<<" ";  
    preorder(root->right);
}

int convertToLeftSumOfAllNodesTree(TreeNode* root){
    if(root == NULL)    // if passed node is null node then return 0;
        return 0;
    if(root->left == NULL and root->right == NULL)  // if it is leaf node it should not get changed.
        return root->data;
    int lstSum = convertToLeftSumOfAllNodesTree(root->left);
    int rstSum = convertToLeftSumOfAllNodesTree(root->right);
    root->data = root->data + lstSum;
    return  rstSum + root->data;    // As root has included left sub tree sum
}
    

int main(){
    TreeNode* root=createNode(10);
    root->left = createNode(-2);
    root->right = createNode(6);
    root->left->left = createNode(8);
    root->left->right = createNode(-4);
    root->right->left = createNode(7);
    root->right->right = createNode(5);
    preorder(root);
    cout<<endl;
    int dummy = convertToLeftSumOfAllNodesTree(root);
    
    preorder(root);
    return 0;
}