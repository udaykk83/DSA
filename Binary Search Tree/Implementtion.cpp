#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* createNode(int data){
    TreeNode* nn=new TreeNode();
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
TreeNode* insertNode(TreeNode* temp,int data){
    if(temp==NULL)
        return createNode(data);
    if(data < temp->data)
        temp->left= insertNode(temp->left,data);
    else
        temp->right= insertNode(temp->right,data);
    // returning the unchanged initial root.
    return temp;
}
int searchNode(TreeNode* temp,int target){
    if(temp == NULL)
        return -1;
    if(temp->data == target)
        return temp->data;
    else if(temp->data < target)
        return searchNode(temp->right,target);
    else
        return searchNode(temp->left,target);
}
void inorder(TreeNode* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void levelOrder(TreeNode* root){
    vector<vector<int> > ans;
    if(root==NULL)
        return ;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> curr;
        int k=0;
        int c=q.size();
        while(k<c){
            TreeNode* temp=q.front();
            q.pop();
            curr.push_back(temp->data);
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            k++;
        }
        ans.push_back(curr);
    }
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
TreeNode* findMinInRightSubTree(TreeNode* dummy){
    while(dummy != NULL and dummy->left != NULL)
        dummy=dummy->left;
    return dummy;
}

TreeNode* deleteNode(TreeNode* root, int key){
    if(root == NULL)
        return root;
    if(root->data > key)
        root->left = deleteNode(root->left, key);
    else if(root->data < key)
        root->right=deleteNode(root->right, key);
    else{
        if(root->left == NULL and root->right == NULL)
            return NULL;
        else if(root->left == NULL){
            TreeNode* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode* temp=root->left;
            free(root);
            return temp;
        }
        else{
            TreeNode* temp=findMinInRightSubTree(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
int main(){
    TreeNode* root=NULL;
    
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    root = insertNode(root,5);
    cout<<"Inorder trversal - "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"search node is "<<searchNode(root,0);
    cout<<endl;
    cout<<"levelOrder trversal - "<<endl;
    levelOrder(root);
    cout<<"delete node is "<<endl;
    root = deleteNode(root,30);
    cout<<"Inorder trversal - "<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}