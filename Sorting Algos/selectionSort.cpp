#include<bits/stdc++.h>
using namespace std;
void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int minValueIndex=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<=a[minValueIndex]){
               minValueIndex=j; 
            }
            swap(a[i],a[minValueIndex]);
        }
    }
}


int main(){
    int a[]={12,11,13,5,6,6};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    selectionSort(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}

