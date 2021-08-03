#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n) 
{ 
    // Find array sum and i*arr[i] with no rotation 
    int arrSum = 0;  // Stores sum of arr[i] 
    int currVal = 0;  // Stores sum of i*arr[i] 
    for (int i=0; i<n; i++) 
    { 
        arrSum = arrSum + arr[i]; 
        currVal = currVal+(i*arr[i]); 
    } 
    
    // Initialize result as 0 rotation sum 
    int maxVal = currVal; 
    cout<<currVal<<endl;
    // Try all rotations one by one and find 
    // the maximum rotation sum. 
    for (int j=1; j<n; j++) 
    {  
        currVal = currVal - arrSum + n*arr[j-1]; //by adding currval you get max value of i*a[i] by rotations. 
        cout<<currVal<<endl;
        if (currVal > maxVal) 
            maxVal = currVal; 
    } 
  
    // Return result 
    return maxVal; 
}

int main(){
    //int a[]={1,2,3,4,5,6,7,8,9,10};
    int a[]={8,3,1,2};
    int l=sizeof(a)/sizeof(a[0]);
    int d=maxSum(a,l);
    //cin>>d;
    
    
    cout<<d<<endl;
   /*
    for(int i=0;i<l;i++)
    cout<<"--"<<a[i]<<"  ";
    */
}