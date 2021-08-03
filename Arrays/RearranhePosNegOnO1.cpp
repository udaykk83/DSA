#include<bits/stdc++.h>
using namespace std;

void PosNeg(int a[],int n){
  int pivot=-1;
  for(int i=0;i<n;i++){
      if(a[i]<0){
        pivot++;
        int temp=a[pivot];
        a[pivot]=a[i];
        a[i]=temp;
      }
   }
  int  pos=pivot+1;int neg=0;
  while(pos<n && neg<pos && a[neg]<0){
    int temp=a[pos];
    a[pos]=a[neg];
    a[neg]=temp;
    pos++;
    neg=neg+2;
  }  
}

void printlist(int a[],int n){
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
  int n,a[] = { -5, -2, 5, 2,4, 7, 1, 8, 0, -8 };
  n=sizeof(a)/sizeof(a[0]);
  printlist(a,n);
  PosNeg(a,n);
  printlist(a,n);
}