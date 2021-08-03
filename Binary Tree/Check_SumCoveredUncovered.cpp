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

int findLeftLeafSum(TreeNode* root){
    if(root->left == NULL and root->right == NULL)
        return root->data;
    if(root->left != NULL)
        return root->data + findLeftLeafSum(root->left);
    else
        return root->data + findLeftLeafSum(root->right);
}

int findRightLeafSum(TreeNode* root){
    if(root->left == NULL and root->right == NULL)
        return root->data;
    if(root->right != NULL)
        return root->data + findLeftLeafSum(root->right);
    else
        return root->data + findLeftLeafSum(root->left);
}

int findUncoveredSum(TreeNode* root){
    if(root == NULL)
        return 0;
    int leftLeafSum=0;
    int rightLeafSum=0;
    //if(root->left != NULL)
        leftLeafSum = findLeftLeafSum(root->left);
    //if(root->right != NULL)
        rightLeafSum = findRightLeafSum(root->right);
    return root->data + leftLeafSum + rightLeafSum;
}
int findSumTree(TreeNode* root){
    if(root == NULL)
        return 0;
    return root->data + findSumTree(root->left) + findSumTree(root->right);
}

 bool checkSumCoveredUncovered(TreeNode* root){
     int sumUncovered=findUncoveredSum(root);
     int totalSum=findSumTree(root);
     int covered=totalSum - sumUncovered;
        if(covered == sumUncovered)
            return true;
        else 
            return false;
 }   

int main(){
    TreeNode* root =createNode(8);
    root->left = createNode(3); 
    root->left->left = createNode(1);
    root->left->right = createNode(8);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(37); 
    root->right = createNode(10);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    preorder(root);
    cout<<endl;

    if(checkSumCoveredUncovered(root))
        cout<<"COVERED == UNCOVERED SUM"<<endl;
    else
        cout<<"NO"<<endl;
    
    preorder(root);
    return 0;
}