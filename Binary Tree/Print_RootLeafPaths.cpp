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

void printVector(vector<int> &path){
    for(int i=0; i<path.size(); i++)
        cout<<path[i]<<" ";
    cout<<endl;
}


void printUtil(TreeNode* root, vector<int> &path){

    if(root == NULL)
        return;
    path.push_back(root->data);
    if(root->left == NULL and root->right == NULL){
        printVector(path);
        return ;
    }
    printUtil(root->left,path);
    printUtil(root->right,path);
    path.pop_back();
}

void printNodeToLeafPath(TreeNode* root){
    if(root == NULL)
        return;
    vector<int> path;
    printUtil(root,path);
} 

int main(){
    TreeNode* root=createNode(1);
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(4); 
    root->left->right = createNode(5); 
    //preorder(root);
    cout<<endl;
    printNodeToLeafPath(root);
    cout<<endl;        
    //preorder(root);
    return 0;
}