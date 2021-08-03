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

void printKSumPath(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &ans, int k){
    if(root == NULL)
        return;
    sum = sum + root->data;
    path.push_back(root->data);
    if(sum == k){   
        vector<int > temp;         
            for(int j=0; j< path.size(); j++){
                temp.push_back(path[j]);
            }
            ans.push_back(temp);
        }
    printKSumPath(root->left, sum, path, ans, k);
    printKSumPath(root->right, sum, path, ans, k);
    path.pop_back();
}
  

int main(){
    TreeNode* root=createNode(10);
    root->left = createNode(28);
    root->right = createNode(13);
 
    root->right->left = createNode(14);
    root->right->right = createNode(15);
 
    root->right->left->left = createNode(21);
    root->right->left->right = createNode(22);
    root->right->right->left = createNode(23);
    root->right->right->right = createNode(24);
   // preorder(root);
    cout<<endl;
    vector<vector<int>> ans;
    vector<int> path;
    int k = 38;
    int sum = 0;
    printKSumPath(root, sum, path, ans, k);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    //preorder(root);
    return 0;
}