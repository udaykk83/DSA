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

int findLevelofNode(TreeNode* root, int targetNode, int level){
    if(root == NULL)
        return 0;
    if(root->data == targetNode)
        return level;
    int ans = findLevelofNode(root->left, targetNode, level + 1);
    if(ans != 0)        // if found already then no need check the remaining right tree elements
        return ans;     // return the answer which is the level from some other part
    ans = findLevelofNode(root->right, targetNode, level + 1);
    return ans;
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

   // preorder(root);
    cout<<endl;
    int targetNode = 11;
    int level = 1;
    cout<<"level of target node is "<<findLevelofNode(root, targetNode, level)<<endl;
    //preorder(root);
    return 0;
}