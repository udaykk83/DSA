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


int findlargestSumTree(TreeNode* root, int &ans){
    if(root == NULL)
        return 0;
    int ls = findlargestSumTree(root->left,ans);
    int rs = findlargestSumTree(root->right,ans);
    int currTreeSum = root->data + ls +rs;
    ans=max(ans,currTreeSum);
    return currTreeSum;
}

int largestSumTree(TreeNode* root){
    if(root == NULL)
        return 0;
    int ans= INT_MIN;
    findlargestSumTree(root, ans);
    return ans;
}



int main(){
    TreeNode* root       =createNode(1);
    root->left = createNode(-2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(-6);
    root->right->right = createNode(2);
    preorder(root);
    cout<<endl;
    cout<<largestSumTree(root);
    cout<<endl;        
    preorder(root);
    return 0;
}