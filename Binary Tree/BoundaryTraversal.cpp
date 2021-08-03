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
vector<int> leftview(TreeNode* root){
    if(root == NULL)
        return {};
    queue<TreeNode*> q;
    vector<int > leftans;
    q.push(root);
    while(!q.empty()){
        TreeNode* tempNode=q.front();
        int n=q.size();
        int c=0;
        if(tempNode->left != NULL or tempNode->right != NULL)
            leftans.push_back(tempNode->data);
        while(c<n){
            tempNode=q.front();
            q.pop();
            if(tempNode->left != NULL)
                q.push(tempNode->left);
            if(tempNode->right != NULL)
                q.push(tempNode->right);
            c++;
        }        
    }
    return leftans;
}
vector<int> bottomview(TreeNode* root){
    vector<int> bottomans;
    if(root == NULL)
        return bottomans;
    int d=0;
    map<int,int> hash;
    queue< pair<TreeNode*,int> > q;
    q.push(make_pair(root,d));
    while(!q.empty()){
        pair<TreeNode*,int> p=q.front();
        q.pop();
        TreeNode* temp=p.first;
        int d=p.second;
        hash[d]=temp->data;
        if(temp->left != NULL)
            q.push(make_pair(temp->left,d-1));
        if(temp->right != NULL)
            q.push(make_pair(temp->right,d+1));
    }
    for(auto it : hash)
        bottomans.push_back(it.second);
}

vector<int> rightview(TreeNode* node){
    vector<int> rightans;
    if(node == NULL)
        return rightans;
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty()){
        TreeNode* temp=q.front();
        int n=q.size();
        int c=0;
        if(temp->left != NULL or temp->right != NULL)
            rightans.push_back(temp->data);
        while(c<n){
            temp=q.front();
            q.pop();
            if(temp->right != NULL)
                q.push(temp->right);
            if(temp->left != NULL)
                q.push(temp->left);
            c++;            
        }
    }
    return rightans;
}
vector<int > boundaryTraversal(TreeNode* root){
    vector<int> left=leftview(root);
    vector<int> bottom=bottomview(root);
    vector<int> right=rightview(root->right);
    reverse(right.begin(),right.end());
    cout<<"left"<<endl;
    for(int j=0; j<left.size(); j++){
        cout<<left[j]<<" ";
    }
    cout<<endl;
    cout<<"bottom"<<endl;
    for(int j=0; j<bottom.size(); j++){
        cout<<bottom[j]<<" ";
    }
    cout<<endl;
    cout<<"right"<<endl;
    for(int j=0; j<right.size(); j++){
        cout<<right[j]<<" ";
    }
    cout<<endl;
    vector<int> boundary;
    boundary.insert(boundary.end(),left.begin(),left.end());
    boundary.insert(boundary.end(),bottom.begin(),bottom.end());
    boundary.insert(boundary.end(),right.begin(),right.end());
    return boundary;
}

int main(){
    TreeNode* root=createNode(20);
    root->left = createNode(8);
    root->left->left = createNode(4);
    root->left->right = createNode(12);
    //root->left->right->left = createNode(10);
    //root->left->right->right = createNode(14);
    root->right = createNode(22);
    root->right->left = createNode(10);
    root->right->right = createNode(25);

    vector<int > res=boundaryTraversal(root);
    cout<<"Boundary Traversal"<<endl;

    for(int j=0; j<res.size(); j++){
        cout<<res[j]<<" ";
    }
        cout<<endl;
    return 0;
}