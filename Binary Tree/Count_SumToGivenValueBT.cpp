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
int findCountOfSumHelper(TreeNode* root, int &ans, int target){
    if(root == NULL)
        return 0;
    int lstSum=findCountOfSumHelper(root->left,ans,target);
    int rstSum=findCountOfSumHelper(root->right,ans,target);
    int sumOfCurrentTree = lstSum + rstSum + root->data;
    if(sumOfCurrentTree == target)
        ans++;
    return sumOfCurrentTree;
}

int countSumToGivenValueBT(TreeNode* root, int target){
    int ans=0;
    if(root == NULL)
        return 0;
    int lstSum=findCountOfSumHelper(root->left,ans,target);
    int rstSum=findCountOfSumHelper(root->right,ans,target);
    if(lstSum + rstSum + root->data == target)
        ans++;
    return ans;
}


int main(){
    TreeNode* root=createNode(5);
    root->left=createNode(-10);
    root->right=createNode(3);
    root->left->left=createNode(9);
    root->left->right=createNode(8);
    root->right->left = createNode(-4);
    root->right->right = createNode(7);
    int target=7;
    cout<<"Count subtrees that sum up to target "<< target<<" is "<<countSumToGivenValueBT(root,target)<<endl;
    return 0;
}