#include <iostream>
using namespace std;

int main(){
	int a[]={8,6,2,4,9,7,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	int t=0;

	for(int i=1;i<n;i++){
		int temp=a[i];
		int j=i-1;
		while(j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		cout<<j<<endl;
		a[j+1]=temp;
	}

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

}