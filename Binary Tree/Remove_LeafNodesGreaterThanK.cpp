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

TreeNode* removeNodesGreaterThanK(TreeNode* root,int level,int k){
    if(root == NULL)
        return NULL;
    root->left =  removeNodesGreaterThanK(root->left, level + 1, k);
    root->right =  removeNodesGreaterThanK(root->right, level + 1, k);
    if(root->left == NULL and root->right == NULL and level < k){        
        return NULL;
        free(root);
    }
    return root;
}

TreeNode* removeNodesGreaterThanSum(TreeNode* root,int currsum,int target){
    if(root == NULL)
        return NULL;
    currsum = currsum + root->data;
    root->left =  removeNodesGreaterThanSum(root->left, currsum, target);
    root->right =  removeNodesGreaterThanSum(root->right, currsum, target);
    if(root->left == NULL and root->right == NULL and currsum > target){        
        return NULL;
    }
    return root;
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
    cout<<"Preorder of tree is ";
    preorder(root);
    cout<<endl;
    int level =1;
    int k = 4;
    //TreeNode* dummy2 = removeNodesGreaterThanK(root,level,k);
    int currsum = 0;
    int target = 11;
    TreeNode* dummy1 =removeNodesGreaterThanSum(root,currsum,target);
    cout<<"After removing Nodes Greater Than Sum ";
    preorder(root);
    cout<<endl;
    return 0;
}