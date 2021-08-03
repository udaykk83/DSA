#include<bits/stdc++.h>
using namespace std;

void timer(int n){
    if(n==0){
        cout<<"time up";
        return;
    }
    cout<<n<<endl;
    timer(n-1);
}

int main(){
    int n=10;
    timer(10);
    return 0;
}

/*
int CountNumbersLessThanMedian(vector<vector<int>>& A,int rows,int cols,int key){
    int c=0;    
    for(int i=0;i<A.size();i++){
        int low=0;
        int high=cols-1;
        int indexCount=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(A[i][mid]<=key){
                indexCount=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        c+= (indexCount+1);
    }
    return c;
}

int findKthElement(vector<vector<int>>& A,int rows,int cols,int k){
    int low=INT_MAX;
    int high=INT_MIN;
    
    for(int i=0;i<rows;i++){
        low=min(low,A[i][0]);
        high=max(high,A[i][A[0].size()-1]);
    }
    int count=0;
    int ans=0;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        count=CountNumbersLessThanMedian(A,rows,cols,mid);
        if(count<k){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    //vector<vector<int>> mat{{1,3,5},  {2,6,9},     {3,6,9}  };

    vector<vector<int>> mat{{1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}};
    int rows=mat.size();
    int cols=mat[0].size();
    int k=5;
    cout<<findKthElement(mat,rows,cols,k);
    return 0;
}*/
