#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){//lat i elements are sorted so no need to disturb them
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
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
    bubbleSort(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}

