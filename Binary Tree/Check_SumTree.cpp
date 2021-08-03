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

bool isSumTree(TreeNode* root){
    if(root == NULL or (root->left == NULL and root->right == NULL))
        return true;
    int a = root->left == NULL ? 0 : root->left->data;
    int b = root->right == NULL ? 0 : root->right->data;
    return (a + b == root->data) and (isSumTree(root->left)) and (isSumTree(root->right));
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
    bool check = isSumTree(root);
    if(check)
        cout<<"is a subTree sum ";
    else
        cout<<"Not a subtree sum";
    cout<<endl;
    preorder(root);
    return 0;
}