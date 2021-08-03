#include <bits/stdc++.h>
using namespace std;
int getmax(int a[],int n){
	int m=a[0];
	for(int i=1;i<n;i++){

		if(a[i]>m)
		m=a[i];
	}
	cout<<m<<"-getmax  ";
	return m;
}

void countingsort(int a[],int n,int pos){

	int count[n]={0};
	int b[n]={0};
	 /*for (int i = 0; i <= key; i++)  
        cout[i] = 0;*/
	for(int i=0;i<n;i++)
		count[((a[i])/pos)%10]++;
	for(int i=1;i<n;i++)
		count[i]=count[i]+count[i-1];
	for(int i=n-1;i>=0;i--)
		b[--count[(((a[i])/pos)%10)]]=a[i];
	for(int i=0;i<n;i++)
		a[i]=b[i];
	cout<<"count";
}

void radixsort(int a[],int n){
	int max=getmax(a,n);

	for(int pos=1;max/pos>0;pos*=10){
		//cout<<"radix ";
		countingsort(a,n,pos);
		}
}

int main(){
	int a[]={8, 2, 4, 77, 2, 1, 200, 6, 1};
	//int size1 = (sizeof(a))/(sizeof(a[0]));
	radixsort(a,9);

	for(int i=0; i<9; i++)
		cout<<a[i]<<" ";

}