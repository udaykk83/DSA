#include<bits/stdc++.h>
using namespace std;

int lastOccurrenceBinarySearch(int nums[],int start,int end,int key){
    int indexPos=-1;

        while(start<=end){
            int mid=(end+start)/2;
            //cout<<mid<<endl;
            if(nums[mid]==key) {
                indexPos=mid;
                start=mid+1;              
            }
            else if(nums[mid]<key)
                start=mid+1;
            else
                end=mid-1;            
        }
   return indexPos;
}

int firstOccurrenceBinarySearch(int nums[],int start,int end,int key){
    int indexPos=-1;

        while(start<=end){
            int mid=(end+start)/2;
            //cout<<mid<<endl;
            if(nums[mid]==key) {
                indexPos=mid;
                end=mid-1;              
            }
            else if(nums[mid]<key)
                start=mid+1;
            else
                end=mid-1;            
        }
   return indexPos;
}

int main(){
int nums[]={1,8,9,58,85,85,85,85,85,214,557,889,4452};
int lengthNums=sizeof(nums)/sizeof(nums[0]);
cout<<lengthNums-1<<endl;
int key=85;

cout<<"first Occurrence at index no "<<firstOccurrenceBinarySearch(nums,0,lengthNums-1,key)<<endl;
cout<<"last Occurrence at index no "<<lastOccurrenceBinarySearch(nums,0,lengthNums-1,key)<<endl;

return 0;
}