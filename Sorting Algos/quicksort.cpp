#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int a[],int l,int h){
	int pivot=a[l];
	int start=l;
	int end=h;
	while(start<end){
		while(a[start]<=pivot)
			start++;
		while(a[end]>pivot)
			end--;
		if(start<end)
			swap(&a[start],&a[end]);
	}
	swap(&a[l],&a[end]);

	return end;
}

void quicksort(int a[],int l,int h){
	if(l<h){
		int pindex=partition(a,l,h);
		quicksort(a,l,pindex-1);
		quicksort(a,pindex+1,h);
	}
}

int main(){
	int a[]={8, 2, 4, 77, 2, 1, 200, 6, 1};
	int n = (sizeof(a))/(sizeof(a[0]));
	quicksort(a,0,n-1);

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";

}