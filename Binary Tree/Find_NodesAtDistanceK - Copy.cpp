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

void printElements(TreeNode* targetNode, int k){
    if(targetNode == NULL)
        return ;
    if(k == 0)
        cout<<targetNode->data<<endl;
    printElements(targetNode->left, k -1);
    printElements(targetNode->right, k - 1);   
}

int findNodesAtKHelper(TreeNode* root, TreeNode* targetNode, int k){
    if(root == NULL)
        return -1;
    if(root == targetNode){
        printElements(targetNode, k);
        return 0;
    }
    int leftDistance = findNodesAtKHelper(root->left, targetNode, k);
    if(leftDistance != -1){
        if(leftDistance + 1 == k)
            cout<<root->data<<endl;
        else{
            findNodesAtKHelper(root->right, targetNode, k-2-leftDistance);
        }
        return leftDistance + 1;
    }

    int rightDistance = findNodesAtKHelper(root->right, targetNode, k);
    if(rightDistance != -1){
        if(rightDistance + 1 == k)
            cout<<root->data<<endl;
        else{
            findNodesAtKHelper(root->left, targetNode, k-2-rightDistance);
        }
        return rightDistance + 1;
    }

    return -1;
}


int findNodesAtDistanceK(TreeNode* root, TreeNode* targetNode, int k){
    if(root == NULL or targetNode == NULL or k < 0)
        return -1;
    return findNodesAtKHelper(root, targetNode, k);
}


int main(){
    TreeNode* root=createNode(1);
    root->left=createNode(7);
    root->right=createNode(5);

    root->left->left=createNode(2);

    root->left->right=createNode(6);
    root->left->right->left=createNode(15);
    root->left->right->right=createNode(11);

    root->right->right=createNode(9);
    root->right->right->left=createNode(4);

    preorder(root);
    cout<<endl;
    int k = 2;
    int element = findNodesAtDistanceK(root, root->left, k);
    if(element == -1)
        cout<<"No elements found";

    return 0;
}