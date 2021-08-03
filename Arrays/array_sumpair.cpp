#include <bits/stdc++.h>
using namespace std;
int getpivotof(int a[],int l,int r){
    if(l>r)
    return -1;
    if(l==r)
    return l;

    int mid=(l+r)/2;
    if(a[l]<a[r])
        getpivotof(a,mid+1,r);
    else    
        getpivotof(a,l,mid-1);
    
}
int sumpair(int a[],int pIndex,int n,int sum){
    
    int l=(pIndex+1)%n;
    int r=a[pIndex];
    int count=0;

    while(l!=r){
        if(a[l]+a[r]==sum)
        {
            count++;
            if(l==(r-1+n)%n)
                return count;
            l=(l+1)%n;
            r=(r-1+n)%n;
        }
        else if(a[l]+a[r]<sum)
            l=(l+1)%n;
        else
            r=(r-1+n)%n;
    }
    return count;
}
int main()
{
    int a[] = {11, 15, 6, 7, 9, 10};
    int sum=19;
    int n=sizeof(a)/sizeof(a[0]);
    int pivotindex=getpivotof(a,0,n-1);
    //int sumpair(a,pivotindex,n,sum);
    cout<<"Array rotated by pivotindex + 1 = "<<pivotindex+1<<endl;
    cout<< sumpair(a,pivotindex,n,sum);//result for 19 is 0;supposed to be 1 19=a[4]+a[5]
    return 0;
}