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

TreeNode* getparent(TreeNode* root, int key){
    if(root == NULL or root->data == key)
        return NULL;
    TreeNode* parent = NULL;
    while(root != NULL){
        if(root->data < key){
            parent = root;
            root = root->right;
        }
        else if(root->data > key){
            parent = root;
            root = root->left;
        }
        else    
            break;
    }
    return parent;
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

    //cout<<"search node is "<<searchNode(root,0);
    //cout<<endl;
    cout<<"levelOrder trversal - "<<endl;
    levelOrder(root);

    //Parent Node of given Node
    int key = 40;
    cout<<"Parent of "<<key<<" ";
    TreeNode* p = getparent(root, key);
    if(p != NULL)
        cout<<"is "<<p->data<<endl;
    else
        cout<<" doesn't exist"<<endl;
    
    
    //SIBLING derived from Parent
    cout<<"sibling of key ";
    TreeNode* sibling = NULL;
    if(p->left != NULL and p->left->data == key)
        sibling = p->right;
    if(p->right != NULL and p->right->data == key)
        sibling = p->left;
    if(sibling != NULL)
        cout<<"is "<<sibling->data<<endl;
    else
        cout<<" doesn't exist"<<endl;
    return 0;
}