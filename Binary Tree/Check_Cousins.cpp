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


bool checkSiblings(TreeNode* root, TreeNode* a, TreeNode* b){
    if(root == NULL)
        return false;
    return ((root->left == a and root->right == b) or (root->left == b and root->right == a)) or(checkSiblings(root->left, a , b)) or(checkSiblings(root->right, a, b));
} 

int getLevel(TreeNode* root, int ab, int level){
    if(root == NULL )
        return 0;
    if(root->data == ab)
        return level;
    int ansLevel = getLevel(root->left, ab, level + 1);
    if(ansLevel != 0)
        return ansLevel;
    ansLevel = getLevel(root->right, ab, level + 1);
    return ansLevel;
}

bool checkCousins(TreeNode* root, TreeNode* a, TreeNode* b){
    if(root == NULL or a == NULL or b == NULL)
        return false;
    if( (getLevel(root, a->data, 1) != getLevel(root, b->data , 1) ))
        return false;    
    if( checkSiblings(root, a, b) == false )
        return true;
    else
        return false;
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

    cout<<"PreOrder is ";
    preorder(root);
    cout<<endl;
    
    bool valid = checkCousins(root, root->right->right, root->left->left);
    if(valid)
        cout<<"yes Cousins"<<endl;
    else
        cout<<"Not Cousins"<<endl;
    
    //preorder(root);
    return 0;
}