#include<bits/stdc++.h>
using namespace std;

void insertionSort(int a[],int n){
    int j,key;
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 and a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}


int main(){
    int a[]={12,11,13,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    insertionSort(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}

