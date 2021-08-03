#include <bits/stdc++.h>
using namespace std;

void cyclic(int a[],int l){
    int t=a[l-1],i;
    for(i=l-1;i>0;i--)
        a[i]=a[i-1];
        a[i]=t;
}

void leftrotate(int a[],int l,int k){
    for(int j=0;j<k;j++){
        int temp=a[0];
        int i;
        for(i=0;i<l-1;i++){
            a[i]=a[i+1];
        }
        a[i]=temp;
    }
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    int l=sizeof(a)/sizeof(a[0]);
    int d=0;
    //cin>>d;
    leftrotate(a,l,2);
    for(int i=0;i<l;i++)
    cout<<"--"<<a[i]<<"  ";
    cout<<endl;
    cyclic(a,l);
    for(int i=0;i<l;i++)
    cout<<"--"<<a[i]<<"  ";
}