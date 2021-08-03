#include<bits/stdc++.h>
using namespace std;
void evenoddarray(int arr[],int n);
int main(){
    int n, arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
  evenoddarray(arr,n);
  return 0;
}
void evenoddarray(int a[],int n){

  int even=n/2;
  int odd=n-even;
  int t[n];
  for(int i=0;i<n;i++)
    t[i]=a[i];
  sort(t,t+n);
  for(int i=n-1;i>-1;){
    a[i]=t[even];
    even--;
    i=i+2;
  }
  for(int i=n-1;i>0;){
    a[i]=t[odd];
    odd++;
    i=i+2;
  }
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

}