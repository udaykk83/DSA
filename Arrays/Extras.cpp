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

void reorderindex(int a[],int in[],int n){
  int temp[n];
  for(int i=0;i<n;i++){
    temp[in[i]]=a[i];
  }
  for (int i=0; i<n; i++)
    { 
       a[i]   = temp[i];
       in[i] = i;
    }
}
void RearrangePosNeg(int a[], int n){
  int pivot=-1;
  for(int i=0;i<n;i++){
    if(a[i]>0){
      pivot++;
      int t=a[pivot];
      a[pivot]=a[i];
      a[i]=t;
    }
  }
}
void reorder(int arr[],int n){
  for(int i=0;i<n;i++){
    if(arr[i]>=0 && i%2==1){
      for(int j=i+1;j<n;j++){
          if(arr[j]<0 && j%2==0)
          {
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp;
            break;
          }
      }
    }
    if(arr[i]<0 && i%2==0){
      for(int j=i+1;j<n;j++){
          if(arr[j]>=0 && j%2==1)
          {
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp;
            break;
          }
      }
    }
  }
}

void reorderij(int a[],int n){
  int temp[n];
  for(int i=0;i<n;i++){
    temp[i]=a[a[i]];
  }
  for (int i=0; i<n; i++)
       a[i]   = temp[i];
}

void printlist(int a[],int n){
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
  /*int m,a[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  m=sizeof(a)/sizeof(a[0]);
  pushZeroToEnd(a,m);
  printlist(a,m);*/

  /*int n,b[] ={1, 2, 0, 0, 0, 3, 6};
  n=sizeof(b)/sizeof(b[0]);  
  pushtoendtraversal(b,n);
  printlist(b,n);*/
  /*
  int arr[] = {50, 40, 70, 60, 90};
  int index[] = {3,  0,  4,  1,  2};
  int n=sizeof(arr)/sizeof(arr[0]);
  reorderindex(arr,index,n);
  printlist(arr,n);
  printlist(index,n);
  */
  /*
  int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 }; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  RearrangePosNeg(arr, n);
  printlist(arr,n); 
  */
  /*
  int arr[] = { 1, -3, 5, 6, -3, 6, 7, -4, 9, 10 }; 
  int n = sizeof(arr)/sizeof(arr[0]);
  reorder(arr,n);
  printlist(arr,n);
  */
 
 //Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’
 int arr[]  = {2, 0, 1, 4, 5, 3};
 int n = sizeof(arr)/sizeof(arr[0]);
  reorderij(arr,n);
  printlist(arr,n);
}