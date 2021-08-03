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

//-------->TC o(N*N)<-------------  
int calculateSum(TreeNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL and root->right == NULL)
        return root->data;
    int ls = calculateSum(root->left);
    int rs = calculateSum(root->right);
    return ls+rs+root->data;
}


int checkSumTree(TreeNode* root){
    if(root == NULL)
        return true;
    if(root->left == NULL and root->right == NULL)
       return true;
    int ls = calculateSum(root->left);
    int rs = calculateSum(root->right);
    if(ls+rs == root->data and checkSumTree(root->left) and checkSumTree(root->right)){
        return true;
    }
    else
        return false;
}
//-------->TC o(N*N)<-----------  

int main(){
    TreeNode* root       =createNode(26);
    root->left = createNode(10);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(6);
    root->right->right = createNode(3);
    preorder(root);
    cout<<endl;
    if(checkSumTree(root))
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;        
    preorder(root);
    return 0;
}