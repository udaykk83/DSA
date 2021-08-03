#include <iostream>
using namespace std;


void mergetogether(int a[],int le[],int leftcount,int re[],int rightcount){
	
	int n1=leftcount;
	int n2=rightcount;
	
	int i=0,j=0,k=0;
	
	while(i<n1 && j<n2){
		if(le[i]<re[j]){
			a[k]=le[i];
			k++;i++;
		}
		else
		{
			a[k]=re[j];
			k++;j++;
		}
	}
	while(i<n1){
		a[k]=le[i];
		k++;i++;
	}
	while(j<n2){
		a[k]=re[j];
		k++;j++;
	}
}


void mergesort(int a[],int n){
		if(n<2)
			return;
	int mid=n/2;
	int left[mid];
	int right[n-mid];

	for(int i=0;i<mid;i++){
		left[i]=a[i];
	}
	for(int i=mid;i<n;i++){
		right[i-mid]=a[i];
	}

	mergesort(left,mid);
	mergesort(right,n-mid);
	mergetogether(a,left,mid,right,n-mid);
	free(left);
    free(right);

}


int main(){
	int a[]={8,6,2,4,9,7,2,1};
	int size=sizeof(a)/sizeof(a[0]);
	mergesort(a,size);
	for(int i=0;i<size-1;i++){
		cout<<a[i]<<"-";
	}
	//cout<<a[size-1];
}