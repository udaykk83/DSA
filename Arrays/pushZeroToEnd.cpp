#include<bits/stdc++.h>
using namespace std;

void pushZeroToEnd(int a[],int n){
  int count=0;
  for(int i=0;i<n;i++){
    if(a[i]!=0){
      a[count]=a[i];
      count++;
    }
  }

  while(count<n){
    a[count]=0;
    count++;
  }
}
void pushtoendtraversal(int a[],int n){

  int pivot=-1;
  for(int i=0;i<n;i++){
    if(a[i]!=0){
      pivot++;
      int t=a[pivot];
      a[pivot]=a[i];
      a[i]=t;
    }
  } 
}
void printlist(int a[],int n){
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
  int m,a[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  m=sizeof(a)/sizeof(a[0]);
  int n,b[] ={1, 2, 0, 0, 0, 3, 6};
  n=sizeof(b)/sizeof(b[0]);
  pushZeroToEnd(a,m);
  printlist(a,m);
  pushtoendtraversal(b,n);
  printlist(b,n);
}