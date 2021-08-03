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
//------------------------>First Approach
TreeNode* findLCAHelper(TreeNode* root, int a, int b, bool &v1, bool &v2){
    if(root == NULL)
        return NULL;
    if(root->data == a){
        v1 = true;
        return root;
    }
    if(root->data == b){
        v2 = true;
        return root;
    }
    TreeNode* left = findLCAHelper(root->left, a, b, v1, v2);
    TreeNode* right = findLCAHelper(root->right, a, b, v1, v2);
    if(left != NULL and right != NULL)
        return root;
    if(left != NULL)
        return left;
    else
        return right;
}

bool searchNode(TreeNode* root, int key){
    if(root == NULL)
        return false;
    if(root->data == key || searchNode(root->left, key) || searchNode(root->right, key))
        return true;
    return false;
}

TreeNode* findLCA(TreeNode* root, int a, int b){
    bool v1 = false;
    bool v2 = false;
    TreeNode* lca = findLCAHelper(root, a, b, v1, v2);
    if(v1 == true and v2 == true)
        return lca;
    if(v1 == false and v2 == false)
        return NULL;
    if(v1 == false and searchNode(lca,a)){
        return lca;
    }
    if(v2 == false and searchNode(lca,b)){
        return lca;
    }
}
//                      First Approach<--------------------------------------


//---------------------------->second Approach
bool findPath(TreeNode* root, int key,  vector<int> &path){
    if(root == NULL)
        return false;
    path.push_back(root->data);
    if(root->data == key)
        return true;
    if(findPath(root->left, key, path) || findPath(root->right, key, path))
        return true;
    path.pop_back();
    return false;
}

int LCASecondApproach(TreeNode* root, int a, int b){
    vector<int> path1,path2;
    bool v1 = findPath(root, a, path1);
    bool v2 = findPath(root, b, path2);
    if(v1 and v2){
        for(int i=0; i<path1.size(); i++){
            if(path1[i] != path2[i]){
                return path1[i-1];
            }
        }
    }
    else{
        return -1;
    }
    return 0;
}



//                             second Approach<-------------------------------

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
    int a = 11, b = 15;
    TreeNode* lca = findLCA(root, a, b);
    cout<<"LCA of "<<a<<" and "<<b<<" is "<<lca->data<<endl; 
    cout<<"LCA second Approach ";
    cout<<LCASecondApproach(root, a, b);

    return 0;
}