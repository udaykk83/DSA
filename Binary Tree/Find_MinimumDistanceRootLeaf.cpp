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

void findMinDistance(TreeNode* root,int height,int &minD){
    if(root == NULL)
       return;
    if(root->left == NULL and root->right == NULL){
        minD = min(minD, height);
    }
    findMinDistance(root->left, height + 1, minD);
    findMinDistance(root->right, height + 1, minD);
}

  

int main(){
    TreeNode* root=createNode(1);
    root->left=createNode(7);
    root->right=createNode(5);

    root->left->left=createNode(2);

    root->left->right=createNode(6);
    root->left->right->left=createNode(5);
    root->left->right->right=createNode(11);

   // root->right->right=createNode(9);
    //root->right->right->left=createNode(4);

    preorder(root);
    cout<<endl;
    int height =0;
    int minD=INT_MAX;
    findMinDistance(root,height,minD);
    cout<<"Min distance from Root to Leaf Node is "<<minD<<endl;
    return 0;
}