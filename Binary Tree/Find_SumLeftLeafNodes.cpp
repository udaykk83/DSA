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
int findLeafNodeSum(TreeNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL and root->right == NULL)
        return root->data;
    return findLeafNodeSum(root->left) + findLeafNodeSum(root->right);
}

void findLeftleafSumApproach_One(TreeNode* root, bool isLeftLeaf, int &sum){
    if(root == NULL)
        return ;
    if(root->left == NULL and root->right == NULL and isLeftLeaf == true)
        sum = sum + root->data;
    findLeftleafSumApproach_One(root->left, true, sum);
    findLeftleafSumApproach_One(root->right, false, sum);
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
    cout<<"All Leaf Nodes sum is "<<findLeafNodeSum(root)<<endl;
    int sum=0;
    bool isLeftLeaf = false;
    findLeftleafSumApproach_One(root, isLeftLeaf, sum);
    cout<<"Left Leaf Nodes Sum Approach 1 is "<<sum<<endl;
    
    cout<<endl;        
    //preorder(root);
    return 0;
}