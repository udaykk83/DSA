#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int num=2;
    for(int j = 2; j <= num/2; j++){
      if (num % j == 0)
         cout<<0;
   }
   cout<<1;
    
    /*/for loop j =0 to B.size()

    {

      vector<int>v;

          for(x=0;x<A.size();x++)

          v.push_back(A[(B[j]+x)%A.size()]);

       ans,push_back(v);

    }

//print the ans
    */
    
    /*
    int A[]={1,2,30,4,5,6,7,8,9};
    int n=sizeof(A)/sizeof(A[0]);
    int c=1;int l=1;
    sort(A,A+n);
    for(int i=0;i<n-1;i++){
        int sum=A[i]+A[i+1];
        if(sum%2==0)
            continue;
        else
        {c++;} 
        int l=max(l,c);  
    c=1;
    
    }

   for(int i=0;i<n;i++)    
    cout<<"--"<<A[i]<<"  ";
    cout<<endl;
    cout<<l;
   
   */
   
   /* int last=INT_MIN;
    int seclast=INT_MIN;
    for(int i=0;i<n;i++)
        last=max(last,A[i]);

     for(int i=0;i<n;i++){    
        if(A[i]!=last)
        seclast=max(seclast,A[i]);
    }



    for(int i=0;i<n;i++)    
    cout<<"--"<<A[i]<<"  ";
    cout<<endl;
    cout<< last<<" "<<seclast <<endl;*/

    /*int d=5;
    //cin>>d;
   leftrotate(a,l,d);
    int pivot=findpivot(a,0,l-1);
    
    cout<<"After Rotating array by "<<d<<" times ";
    for(int i=0;i<l;i++)    
    cout<<"--"<<a[i]<<"  ";
    cout<<endl;
    cout<<"pivot element index is "<<pivot<<endl;
    cout<<" min "<<a[(pivot+1)%l]<<endl;
    cout<<"Binary Search -> index of "<<a[2]<<" is "<<indexofelement(a,l,a[2]);*/
    return 0;
}