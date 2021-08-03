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

int findmaxSumPath(TreeNode* root, int &maxSum){
    if(root == NULL)
        return 0;
    if(root->left == NULL and root->right == NULL)
        return root->data;
    int ls = findmaxSum(root->left, maxSum);
    int rs = findmaxSum(root->right, maxSum);
    int max1 = max(root->data, (root->data + max(ls , rs)));
    int max2 = max(max1, (root->data + ls + rs));
    maxSum = max(maxSum, max2);
    return max1;
}
  

int main(){
    TreeNode* root=createNode(2);
    root->left=createNode(4);
    root->right=createNode(1);

    root->left->left=createNode(7);

    root->left->right=createNode(10);

   // preorder(root);
    cout<<endl;
    int maxSum =0;
    int k =findmaxSumPath(root, maxSum);
    cout<<"Max sum path value is "<<maxSum<<endl;
    //preorder(root);
    return 0;
}