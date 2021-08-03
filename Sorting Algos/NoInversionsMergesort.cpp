#include <bits/stdc++.h>
using namespace std;


/*int mergetogether(int a[],int le[],int leftcount,int re[],int rightcount){
	int inv=0;
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
			inv=inv+(leftcount+1-i);
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
	return inv;
}


int mergesort(int a[],int n){
	int inv=0;
	if(n>2){
		int mid=n/2;
		int left[mid];
		int right[n-mid];

		for(int i=0;i<mid;i++){
			left[i]=a[i];
		}
		for(int i=mid;i<n;i++){
			right[i-mid]=a[i];
		}

		inv=inv+mergesort(left,mid);
		inv=inv+mergesort(right,n-mid);
		inv=inv+mergetogether(a,left,mid,right,n-mid);
		free(left);
		free(right);
	}
	return inv;

}
*/

int main(){
	//int a[]={8, 4, 2, 1};
	//int size=sizeof(a)/sizeof(a[0]);
	//int ans=mergesort(a,size);
	/*for(int i=0;i<size-1;i++){
		cout<<a[i]<<"-";
	}*/
	int N=20;
	int x=ceil(sqrt(N));
	int y=N/x; //+ (N%x!=0);
	

	cout<<x<<endl;
	cout<<y;
}