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

bool checkHelper(TreeNode* root, int currLeafLevel, int &firstLeafLevel){
    if(root == NULL)
        return true;
    if(root->left == NULL and root->right == NULL){
        if(firstLeafLevel == 0){
            firstLeafLevel = currLeafLevel;
            return true;
        }
        if(firstLeafLevel == currLeafLevel)
            return true;
        else
            return false;
    }
        return checkHelper(root->left,currLeafLevel + 1,firstLeafLevel) and checkHelper(root->right,currLeafLevel + 1,firstLeafLevel);
}

bool checkLeavesLevel(TreeNode* root){
    if(root == NULL)
    return true;
    if(root->left == NULL and root->right == NULL)
        return true;
    int currLeafLevel=0, firstLeafLevel=0;
    return checkHelper(root,currLeafLevel,firstLeafLevel);
}
   

int main(){
    TreeNode* root       =createNode(10);
    root->left           = createNode(8);
    root->right          = createNode(2);
    root->left->left    = createNode(3);
    root->left->right   = createNode(5);
    preorder(root);
    cout<<endl;
    if(checkLeavesLevel(root))
        cout<<"Leaves at same level"<<endl;
    else
        cout<<"NOT at same level"<<endl;
    
    preorder(root);
    return 0;
}