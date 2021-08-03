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

int findMinHeightApproach_One(TreeNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL and root->right== NULL)
        return 1;
    if(root->left == NULL)
        return 1 + findMinHeightApproach_One(root->right);
    if(root->right == NULL)
        return 1 + findMinHeightApproach_One(root->left);
    return 1 + min(findMinHeightApproach_One(root->left), findMinHeightApproach_One(root->right));
}

void findMinHeightApproach_Two(TreeNode* root,int height,int &minHeight){
    if(root == NULL)
        return;
    if(root->left == NULL and root->right== NULL){
        minHeight = min(height,minHeight);
        return;
    }
    findMinHeightApproach_Two(root->left, height + 1, minHeight);
    findMinHeightApproach_Two(root->right,height + 1, minHeight);
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
    //preorder(root);
    cout<<endl;
    cout<<"find Min Height Approach 1 is "<<findMinHeightApproach_One(root)<<endl;
    int height = 1;
    int minHeight = INT_MAX;
    findMinHeightApproach_Two(root,height,minHeight);
    cout<<"find Min Height Approach 2 is "<<minHeight;
    cout<<endl;        
    //preorder(root);
    return 0;
}