#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
};
int helperBalanced(TreeNode* root,bool &ans){
    if(root == NULL)
        return -1;
    int lh=helperBalanced(root->left,ans);
    int rh=helperBalanced(root->right,ans);
    if(abs(lh-rh)>1)
        ans=false;
    return max(lh,rh)+1;
}

bool CheckIsBaalanced(TreeNode* root){
    bool ans=true;
    int dummy=helperBalanced(root,ans);
    return ans;

}

TreeNode* createNode(int key){
    TreeNode* nn=new TreeNode();
    nn->data=key;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

int main(){
    TreeNode* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->left->left=createNode(6);
    if(CheckIsBaalanced(root))
        cout<<"BALANCED";
    else
        cout<<"NOT BALANCED";
    return 0;
}