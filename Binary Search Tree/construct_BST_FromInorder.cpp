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


int findMax(vector<int> &arr, int l,int r){
    int maxi = arr[l];
    int ans = l;
    for(int i=l+1; i<=r; i++){
        if(arr[i]>maxi){
            maxi = arr[i];
            ans = i;
        }
    }
    return ans;
}

TreeNode* buildBST(vector<int> &arr, int l,int r){
    if(l>r)
        return NULL;
    int index = findMax(arr, l,r);
    TreeNode* root = createNode(arr[index]);
    if(l == r)
        return root;
    root->left = buildBST(arr,l,index-1);
    root->right = buildBST(arr,index+1,r);
    return root;
}



int main(){
    vector<int> arr{5, 10, 40, 30, 28};
    int n= arr.size();
    TreeNode* root = buildBST(arr,0,n-1);
    
    cout<<"Inorder trversal - "<<endl;
    inorder(root);
    cout<<endl;

    //cout<<"search node is "<<searchNode(root,0);
    //cout<<endl;
    cout<<"levelOrder trversal - "<<endl;
    levelOrder(root);
}