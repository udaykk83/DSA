#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int start,int end){
        int pivot=a[end];
        int partitionIndex=start;
        for(int i=start;i<end;i++){
            if(a[i]<=pivot){
                swap(a[i],a[partitionIndex]);
                partitionIndex++;
            }
        }
        swap(a[end],a[partitionIndex]);
        
        cout<<"pivot and partition index "<< pivot<<" "<<partitionIndex<<endl;

        return partitionIndex;
}


void QuickSort(int a[],int start,int end){
    if(start>=end){
        return;
    }
    int pivotIndex=partition(a,start,end);
    QuickSort(a,start,pivotIndex -1);
    QuickSort(a,pivotIndex +1,end);
}


int main(){
    int a[]={12,11,13,5,6,6};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    QuickSort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}

