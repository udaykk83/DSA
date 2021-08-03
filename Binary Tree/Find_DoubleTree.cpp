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

void generateDoubleTree(TreeNode* root){
    if(root == NULL)
        return;
    generateDoubleTree(root->left);
    generateDoubleTree(root->right);
    TreeNode* nn =new TreeNode();
    nn->data= root->data;
    nn->right = NULL;
    nn->left = root->left;
    root->left = nn;
    return;
}
  

int main(){
    TreeNode* root=createNode(1);
    root->left=createNode(7);
    root->right=createNode(5);

    root->left->left=createNode(2);

    root->left->right=createNode(6);
    root->left->right->left=createNode(5);
    root->left->right->right=createNode(11);

    root->right->right=createNode(9);
    root->right->right->left=createNode(4);

    preorder(root);
    cout<<endl;
    generateDoubleTree(root);
    preorder(root);
    return 0;
}