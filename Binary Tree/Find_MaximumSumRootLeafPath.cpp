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

void findMaxSumNodeToLeafPath(TreeNode* root, int currsum, int &maxSum){
    if(root == NULL)
        return;
    currsum = currsum*10 + root->data;
    if(root->left == NULL and root->right == NULL){
        maxSum = max(maxSum, currsum);
        cout<<currsum<<endl;
        return;
    }
    findMaxSumNodeToLeafPath(root->left, currsum, maxSum);
    findMaxSumNodeToLeafPath(root->right, currsum, maxSum);
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
    int currsum = 0;
    int maxSum = INT_MIN;
    findMaxSumNodeToLeafPath(root, currsum, maxSum);
    cout<<maxSum;
    cout<<endl;        
    //preorder(root);
    return 0;
}