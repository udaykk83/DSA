#include <bits/stdc++.h>
using namespace std;
void countingsort(int a[],int key,int n){
	int cout[key+1]={0};
	int b[n];
	 /*for (int i = 0; i <= key; i++)  
        cout[i] = 0;*/
	for(int i=0;i<n;i++)
		cout[a[i]]++;
	for(int i=1;i<=key;i++)
		cout[i]=cout[i]+cout[i-1];
	for(int i=n-1;i>=0;i--)
		b[--cout[a[i]]]=a[i];
	for(int i=0;i<n;i++)
		a[i]=b[i];

}

int main(){
	int a[]={8, 2, 4, 77, 2, 1, 200, 6, 1};
	//int size1 = (sizeof(a))/(sizeof(a[0]));
	countingsort(a,200,9);

	for(int i=0; i<9; i++)
		cout<<a[i]<<" ";

}