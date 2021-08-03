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



vector<vector<int >> diagonalOrderTraversal(TreeNode* root){
    vector<vector<int >> ans;
    if(root == NULL)
        return ans;
    int d=0;
    queue<pair<TreeNode* ,int>> q;
    map<int, vector<int> > hash;
    q.push(make_pair(root,d));
    while (!q.empty())
    {
        pair<TreeNode*, int> p=q.front();
        q.pop();
        TreeNode* tempNode=p.first;
        int d=p.second;
        hash[d].push_back(tempNode->data);
        if(tempNode->left != NULL)
            q.push(make_pair(tempNode->left,d-1));
        if(tempNode->right != NULL)
            q.push(make_pair(tempNode->right,d));
    }
    for(auto it : hash)
        ans.push_back(it.second);
    return ans;
}


int main(){
    TreeNode* root=createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    vector<vector<int >> res=diagonalOrderTraversal(root);
    cout<<"Diagonal order Traversal"<<endl;
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}