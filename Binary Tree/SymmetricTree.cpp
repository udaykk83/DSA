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
void preorder(TreeNode* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);    
    preorder(root->right);
}
bool checkSymmetry(TreeNode* root1,TreeNode* root2){
    if(root1==NULL and root2==NULL)
        return true;    
    if(root1==NULL or root2==NULL)
        return false;
    if(root1->data==root2->data){
        return checkSymmetry(root1->left,root2->right) && checkSymmetry(root1->right,root2->left);
    }
    return false;
}

bool isSymmetric(TreeNode* root){
    return checkSymmetry(root->left,root->right);
}
void invertTree(TreeNode* root){
    if(root==NULL)
        return;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left,root->right);
}


int main(){
    TreeNode* root =createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    preorder(root);
    cout<<endl;
    if(isSymmetric(root))
        cout<<"tree is symmetric";
    else
        cout<<"Not symmetric";
    cout<<endl;
    invertTree(root);    
    preorder(root);
    return 0;
}