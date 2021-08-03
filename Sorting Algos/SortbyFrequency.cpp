#include <iostream>
using namespace std;


void sortbyfrequency(int a[],int n){
	int f[n];
	int d=-1;
	for(int i=0;i<n;i++){
		int c=1;
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				c++;
				f[j]=d;
			}
			if(f[i]!=d){
				f[i]=c;
			}			
		}
	}

	for(int k=0;k<n;k++){
		if(f[k]!=d){
			for(int l=1;l<=f[k];l++)
				cout<<a[k]<<" ";
		}
	}
	cout<<"fgfgfsgfas"<<endl;
}

int main(){
	int a[]={2, 5, 2, 8, 5, 6, 8, 8};
	int size=sizeof(a)/sizeof(a[0]);
	sortbyfrequency(a,size);
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
}