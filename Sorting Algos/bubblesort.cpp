#include <iostream>
using namespace std;

int main(){
	int a[]={8,6,2,4,9,7,2,1};
	int size=sizeof(a)/sizeof(a[0]);
	int t=0;
	for(int i=0;i<=size-1;i++){
		for(int j=i+1;j<=size-1;j++){
		if(a[j]<a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}	
		}
	}

	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";

}