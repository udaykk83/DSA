#include <bits/stdc++.h>
using namespace std;

void reversearray(int a[],int s,int e){
    while(s<e){
        int temp=a[s];
        a[s]=a[e];
        a[e]=temp;
        s++;e--;
    }
}
void leftrotate(int a[],int l,int k){
    if(k==0)
    return;
    k=k%l;

    reversearray(a,0,k-1);
    reversearray(a,k,l-1);
    reversearray(a,0,l-1);
}
void rightrotate(int a[],int l,int k){
    if(k==0)
    return;
    k=k%l;

    reversearray(a,0,l-1);
    reversearray(a,0,k-1);
    reversearray(a,k,l-1);
    
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    int l=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<l;i++)
    cout<<"--"<<a[i]<<"  ";
    int d=0;
    //cin>>d;
    leftrotate(a,l,5);
    for(int i=0;i<l;i++)
    cout<<"--"<<a[i]<<"  ";
    rightrotate(a,l,5);
    for(int i=0;i<l;i++)
    cout<<"--"<<a[i]<<"  ";
}