#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
void push(Node **topref,int newdata){
    Node *newnode=new Node();
    newnode->data=newdata;
    newnode->next=*topref;
    *topref=newnode;
    return;
}

void remove(Node *top){
    cout<<"____________________"<<endl;
    cout<<top->data<<" "<<endl;
    top=top->next;
    Node *temp=top;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<"____________________"<<endl;
}
void pop(Node **topref){
    Node *temp=*topref;
    Node *topp=*topref;
    topp=topp->next;
    *topref=topp;
    free(temp);

}
void print(Node *top){
    Node *temp=top;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main(){
    Node *top=NULL;
    push(&top,2);
    push(&top,9);
    push(&top,8);
    push(&top,5);
    pop(&top);
    remove(top);//doubt in this section;
    print(top);

}