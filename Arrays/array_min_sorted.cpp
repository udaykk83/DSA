#include <bits/stdc++.h>
using namespace std;

int minsortedrotated(int a[],int l,int r){
    
    if(l>r)
        return -1;
    if(l==r)
        return a[l];
    int m=l+(r-l)/2;
    if(m<r && a[m+1]<a[m])
        return a[m+1];
    if(l<m && a[m]<a[m-1])
        return a[m];
    if(a[m]<a[r])
        minsortedrotated(a,l,m-1);
    else
    {
        minsortedrotated(a,m+1,r);
    }
    
        
}
int minsorted(int a[],int l,int r){
    while(l<r){
        int m=l+(r-l)/2;
        if(a[m]>a[r])
            l=m+1;
        else if(a[m]==a[r])
            r--;
        else
            r=m;
    }
    return a[r];
}
int main(){
    int a[]={0, 6, 1, 2, 0, 5};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<minsortedrotated(a,0,n-1)<<endl;//only for different elements(non repetitive)
    cout<<minsorted(a,0,n-1);
    
}