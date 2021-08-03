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

bool checkChildrenSum(TreeNode* root){
    if(root == NULL)    
        return true;
    if(root->left == NULL and root->right == NULL)  
        return true;
    int lstSum=0;int rstSum=0;
    if(root->left != NULL)
        lstSum = root->left->data;
    if(root->right != NULL)
    rstSum = root->right->data;
    if(root->data == rstSum + lstSum and checkChildrenSum(root->left) and checkChildrenSum(root->right))
        return true;
    else
        return false;
}
    

int main(){
    TreeNode* root       =createNode(10);
    root->left           = createNode(8);
    root->right          = createNode(2);
    root->left->left    = createNode(3);
    root->left->right   = createNode(5);
    root->right->right  = createNode(2);
    preorder(root);
    cout<<endl;
    if(checkChildrenSum(root))
        cout<<"Children Sum Property SATISFIES"<<endl;
    else
        cout<<"NO"<<endl;
    
    preorder(root);
    return 0;
}