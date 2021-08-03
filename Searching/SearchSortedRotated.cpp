#include<bits/stdc++.h>
using namespace std;

int binarySearch(int nums[],int start,int end,int key){
    if (end < start)
            return -1;
    int mid=start+(end-start)/2;
    if(nums[mid]==key)
        return mid;
    else if(nums[mid]<key)
        return binarySearch(nums,mid+1,end,key);
    else
     return binarySearch(nums,start,mid-1,key);
    return -1;
}

int findPivot(int nums[],int start,int end){
    int mid=start+(end-start)/2;
    if(nums[mid]>nums[mid+1])
        return mid;
    else{
        if(nums[start]>nums[mid])
            return findPivot(nums,start,mid-1);   
        else
            return findPivot(nums,mid+1,end);  
    }
    return -1;
}

int searchElement(int nums[],int numsSize,int key){
    int pivot=findPivot(nums,0,numsSize-1);
    /*if(pivot =-1)                                   //For NO PIVOT element in the array
        binarySearch(nums,0,numsSize-1,key);*/
    if(nums[pivot]==key)
    return pivot;
    if(nums[0]<=key)
        return binarySearch(nums,0,pivot-1,key);
    if(nums[0]>key)
        return binarySearch(nums,pivot+1,numsSize-1,key);
}

int main(){

    int nums[]={4,5,6,7,0,1,2 };
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int key=3;
    cout<<searchElement(nums,numsSize,key)<<endl;
    return 0;
}
