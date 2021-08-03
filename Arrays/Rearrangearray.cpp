#include<bits/stdc++.h>
using namespace std;
void fixarray(int arr[],int n);
int main(){
    int n, arr[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 };
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
  fixarray(arr,n);
  return 0;
}
void fixarray(int a[],int n){

  int i,j,temp;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(a[j]==i){
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
        break;
      }
    }
  }
  for(i=0;i<n;i++){
    if(a[i]!=i){
      a[i]=-1;
    }
  }
  for(i=0;i<n;i++)
    cout<<a[i]<<" ";

}