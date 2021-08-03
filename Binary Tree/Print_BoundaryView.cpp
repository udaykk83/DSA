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
void printleftView(TreeNode* root, vector<int > &ans){
    if(root == NULL)
        return;
    if(root->left != NULL){
        ans.push_back(root->data);
        printleftView(root->left, ans);
    }
    else if(root->right != NULL){
        ans.push_back(root->data);
        printleftView(root->right, ans);
    }
}

void printRightView(TreeNode* root, vector<int > &ans){
    if(root == NULL)
        return;
    if(root->right != NULL){
        printRightView(root->right, ans);
        ans.push_back(root->data);
    }
    else if(root->left != NULL){
        printRightView(root->left, ans);
        ans.push_back(root->data);
    }     
}

void printLeaves(TreeNode* root, vector<int > &ans, vector<int > &leaf){
    if(root == NULL)
        return;
    if(root->left == NULL and root->right == NULL){
        ans.push_back(root->data);
        leaf.push_back(root->data);
        return;
    } 
    printLeaves(root->left, ans, leaf);
    printLeaves(root->right, ans, leaf);
}


void printBoundaryView(TreeNode* root){
    if(root == NULL)
        return;
    vector<int > ans;

    ans.push_back(root->data);

    printleftView(root->left, ans);  //print left view not leaves
    vector<int > leaf;
    printLeaves(root->left, ans, leaf);
    printLeaves(root->right, ans, leaf);
    printRightView(root->right, ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<leaf.size(); i++){
        cout<<leaf[i]<<" ";
    }
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
    printBoundaryView(root);
    //preorder(root);
    return 0;
}