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

bool rootTOLeafPathEqualGIvenSum(TreeNode* root, int target){
    if(root == NULL)
        return false;
    if(root->left == NULL and root->right == NULL and root->data == target)
        return true;
    return rootTOLeafPathEqualGIvenSum(root->left, target - root->data) || rootTOLeafPathEqualGIvenSum(root->right, target - root->data);
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
    int target = 19;
    if(rootTOLeafPathEqualGIvenSum(root, target))
        cout<<"Path Exists"<<endl;
    else
        cout<<"Path Doesn't Exist"<<endl;
    return 0;
}