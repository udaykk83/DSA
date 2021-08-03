#include <bits/stdc++.h>
using namespace std;

int indexofelement(int a[],int len,int key){
    int l=0,r=len-1,mid;
    while(l<=r){
        mid=(l+r)/2;

        if(a[mid]==key)
            return mid;
        else if(a[l]<=a[mid]){
            if(a[l]<=key && key<=a[mid])
                r=mid-1;
                else
                l=mid+1;
        }
        else            
        {
            if(a[mid]<=key && key<=a[r])
                l=mid+1;
            else
                r=mid-1;
            

        }
    }
    return -1;
}
int findpivot(int a[],int l,int r){
    if(r<l)
    return -1;
    if(l==r)
    return l;
        int mid=(l+r)/2;
        if(a[l]<=a[mid])
            findpivot(a,mid+1,r);
        else
            findpivot(a,l,mid-1);
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
    for(int i=0;i<l;i++)    
    cout<<"--"<<a[i]<<"  ";
    cout<<endl;
    int d=5;
    //cin>>d;
   leftrotate(a,l,d);
    int pivot=findpivot(a,0,l-1);
    
    cout<<"After Rotating array by "<<d<<" times ";
    for(int i=0;i<l;i++)    
    cout<<"--"<<a[i]<<"  ";
    cout<<endl;
    cout<<"pivot element index is "<<pivot<<endl;
    cout<<" min "<<a[(pivot+1)%l]<<endl;
    cout<<"Binary Search -> index of "<<a[2]<<" is "<<indexofelement(a,l,a[2]);
}