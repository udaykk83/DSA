#include <iostream>
using namespace std;
#define NA -1

void movetoend(int mn[],int n){
	int j=n-1;
	for(int i=n-1;i>=0;i--){
		if(mn[i]!=NA)
			mn[j--]=mn[i];
	}
}

void merge(int mn[],int ml,int n[],int nl){
	movetoend(mn,(ml+nl));
	//initial positions of arrays
	int i=nl;//for mn
	int j=0;//for n
	int k=0;//for modified array

	while(k<ml+nl){
		if(i<ml+nl && mn[i]<=n[j])
			mn[k++]=mn[i++];
		else if(j==nl)
			mn[k++]=mn[i++];
		else
			mn[k++]=n[j++];//dump to end as array n is sorted
						
	}

	
}


int main(){
	int mn[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
   	int n[] = {5, 7, 9, 25};
    
   	int nl = sizeof(n) / sizeof(n[0]);
   	int ml = sizeof(mn) / sizeof(mn[0]) - nl;
	merge(mn,ml,n,nl);
	for(int i=0;i<(sizeof(mn) / sizeof(mn[0]));i++){
		cout<<mn[i]<<" ";
	}
}