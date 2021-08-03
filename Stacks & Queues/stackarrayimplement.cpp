#include <bits/stdc++.h>
using namespace std;
//#define n 10;
int a[3];
int top=-1;
void push(int v){
    //int v=0;
    //cout<<"Enter value to add";
    //cin>>v;
    top++;
    a[top]=v;
    return;
}
void pop(){
    top--;
}

void peek(){
    cout<<a[top]<<endl;

}
bool empty(){
    if(top==-1)
        return true;
    else
        return false;   
}
void print(){
for(int i=top;i>=0;i--)
    cout<<a[i]<<" ";
}
int main(){
    push(5);
    push(3);
    push(1);
    pop();
    peek();
    print();
    bool b=empty();
    if(b)
    cout<<"111";
    else
    {
        cout<<"0000";
    }
    

}