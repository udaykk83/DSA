#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
void printList(Node* temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void push(Node** headref,int value){
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=*headref;
    *headref=newnode;
}
Node* reverseRecursivelyList(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* ans=reverseRecursivelyList(head->next);
    head->next->next=head;
    head->next=NULL;
    return ans;
}
Node* reverseIterative(Node* head){
    if(head==NULL)
        return head;
    else if(head->next==NULL)
        return head;
    Node* curr=head;
    Node* prev=NULL;
    Node* after=NULL;
    while(curr != NULL){
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;

    }
    return prev;
}

int main(){
    Node* head=NULL;
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printList(head);
    cout<<"recursively  ";
    head=reverseRecursivelyList(head);
    printList(head);
    head=reverseRecursivelyList(head);
    cout<<"iteratively  ";  
    head=reverseIterative(head);
    printList(head);
    return 0;
}