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
int helperDiameter(TreeNode* root,int &ans){
        if(root==NULL)
            return -1;
        int left_height=helperDiameter(root->left,ans);
        int right_height=helperDiameter(root->right,ans);
        ans=max(ans,left_height+right_height+2);
        return (max(left_height,right_height)+1);
}

int getDiameter(TreeNode* root){
    int ans=INT_MIN;
    if(root == NULL)
        return 0;
    int dummy=helperDiameter(root,ans);
    return ans;
}

int main(){
    TreeNode* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->left->left->left=createNode(6);
    cout<<getDiameter(root)<<endl;
    return 0;
}