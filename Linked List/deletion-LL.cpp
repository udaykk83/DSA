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
void deleteKey(Node** headref,int key){
    Node* curr=*headref;
    Node* prev=NULL;
    if(curr==NULL){
        cout<<"head doesn't exist"<<endl;
        return;
    }
    if(curr!=NULL and curr->data==key){
        *headref=curr->next;
        return;
    }
    while(curr!=NULL and curr->data!=key){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<"Not found"<<endl;
        return;
    }
    prev->next=curr->next;
    curr->next=NULL;
}
void deletePosition(Node** headref,int pos){
    Node* temp=*headref;
    Node* prev=NULL;
    if(pos==1){
        *headref=temp->next;
        return;
    }
    int c=1;
    while(temp!=NULL and c!=pos){
        c++;
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"invalid"<<endl;
        return;
    }
    prev->next=temp->next;
    temp->next=NULL;
}
int lengthList(Node* temp){
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

int main(){
    Node* head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);

    printList(head);
    deletePosition(&head,2);
    printList(head);
    push(&head,6);
    printList(head);
    deleteKey(&head,3);
    printList(head);
    cout<<"length is "<<lengthList(head);

    return 0;
}