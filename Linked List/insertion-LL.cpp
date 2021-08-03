#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
void printlist(Node *temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void pushFront(Node** headref,int value){
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=*headref;
    *headref=newnode;
}
void inserAfter(Node *temp,int pos,int value){
    if(pos==1){
        //cout<<"error";
        return;
    }
    int c=1;
    while(temp!=NULL && c<pos){
        c++;
        temp=temp->next;
    }
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=temp->next;
    temp->next=newnode; 
}
void atLast(Node** headref,int value){
    Node *tail=*headref;
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=NULL;
    if(*headref==NULL){
        *headref=newnode;
        return;
    }
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=newnode;
}

int main(){
    Node* head=NULL;
    atLast(&head,16);
    pushFront(&head,2);
    pushFront(&head,9);
    pushFront(&head,13);
    atLast(&head,16);
    pushFront(&head,13);
    pushFront(&head,13);
    Node* temp=head;
    inserAfter(temp,3-1,11);
    atLast(&head,66);
    printlist(head);
    return 0;
}





