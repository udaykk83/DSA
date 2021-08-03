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

void findLeftView(TreeNode* root, int level, int &maxLevel){
    if(root == NULL)
        return ;
    if(level >= maxLevel){
        cout<<root->data<<endl;
        maxLevel++;
    }
    findLeftView(root->left, level + 1, maxLevel);
    findLeftView(root->right, level + 1, maxLevel);
}

void findRightView(TreeNode* root, int level, int &maxLevel){
    if(root == NULL)
        return ;
    if(level >= maxLevel){
        cout<<root->data<<endl;
        maxLevel++;
    }
    findRightView(root->right, level + 1, maxLevel);
    findRightView(root->left, level + 1, maxLevel);
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
    cout<<"Left view is "<<endl;
     int maxLevel = 0;
    int level = 0;
    findLeftView(root, level, maxLevel);

    cout<<"Right view is "<<endl;
    maxLevel = 0;
    level = 0;
    findRightView(root, level, maxLevel);

    //preorder(root);
    return 0;
}