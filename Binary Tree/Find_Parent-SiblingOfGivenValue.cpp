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

TreeNode* findParent(TreeNode* root, int key){
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return NULL;
    if( (root->left != NULL and root->left->data == key) || (root->right != NULL and root->right->data == key))
        return root;
    TreeNode* parent = findParent(root->left, key);
    if(parent != NULL)
        return parent;
    else
        parent = findParent(root->right, key);
    return parent;
}

TreeNode* findSibling(TreeNode* root, int key){
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return NULL;
    if(root->left != NULL and root->left->data == key)
        return root->right;
    if(root->right != NULL and root->right->data == key)
        return root->left;
    TreeNode* s = findSibling(root->left, key);
    if(s != NULL)
        return s;
    s =findSibling(root->right, key);
    return s;
}
  
bool checkSiblings(TreeNode* root, TreeNode* a, TreeNode* b){
    if(root == NULL or root->left == NULL or root->right == NULL)
        return false;
    if( root->left->data == a->data and root->right->data == b->data) 
        return true;
    if(root->left->data == b->data and root->right->data == a->data) 
        return true;
    bool check = checkSiblings(root->left, a , b);
    if(check == true)
        return true;
    check = checkSiblings(root->right, a, b);
    return check; 
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
    int key = 11;
    cout<<"key is "<<key<<endl;
    TreeNode* parent = findParent(root, key);
    cout<<"Parent of given key is "<<parent->data<<endl;

    TreeNode* sibling = findSibling(root, key);
    cout<<"Sibling of given key is "<<sibling->data<<endl;
    
    cout<<root->data<<" "<<root->left->right->left->data<<" "<<root->left->right->right->data<<endl;
    bool valid = checkSiblings(root, root->right->right->left, root->left->right->right);
    if(valid)
        cout<<"yes siblings"<<endl;
    else
        cout<<"Not siblings"<<endl;
    
    //preorder(root);
    return 0;
}