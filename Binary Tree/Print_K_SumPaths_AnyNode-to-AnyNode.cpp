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

void printKSumPath(TreeNode* root, vector<int> &path, vector<vector<int>> &ans, int k){
    if(root == NULL)
        return;
    path.push_back(root->data);
    printKSumPath(root->left, path, ans, k);
    printKSumPath(root->right, path, ans, k);
    
    int sum = 0;
    for(int i=path.size()-1; i>=0; i--){
        sum = sum + path[i];
        vector<int > temp;
        if(sum == k){            
            for(int j=i; j< path.size(); j++){
                temp.push_back(path[j]);
            }
        }
        ans.push_back(temp);
    }
    path.pop_back();
}
  

int main(){
    TreeNode* root=createNode(2);
    root->left=createNode(-1);
    root->right=createNode(4);

    root->left->left=createNode(6);

    root->left->right=createNode(7);
    root->left->right->right=createNode(3);
   // preorder(root);
    cout<<endl;
    vector<vector<int>> ans;
    vector<int> path;
    int k = 6;
    printKSumPath(root, path, ans, k);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    //preorder(root);
    return 0;
}