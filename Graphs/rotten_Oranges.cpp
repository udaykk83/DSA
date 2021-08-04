/*
Rotten Oranges
Problem Description

Given a matrix of integers A of size N x M consisting of 0, 1 or 2.

Each cell can have three values:

The value 0 representing an empty cell.

The value 1 representing a fresh orange.

The value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 instead.

Note: Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.



Problem Constraints
1 <= N, M <= 1000

0 <= A[i][j] <= 2



Input Format
The first argument given is the integer matrix A.



Output Format
Return the minimum number of minutes that must elapse until no cell has a fresh orange.

If this is impossible, return -1 instead.



Example Input
Input 1:

A = [   [2, 1, 1]
        [1, 1, 0]
        [0, 1, 1]   ]
Input 2:

 
A = [   [2, 1, 1]
        [0, 1, 1]
        [1, 0, 1]   ]


Example Output
Output 1:

 4
Output 2:

 -1


Example Explanation
Explanation 1:

 Max of 4 using (0,0) , (0,1) , (1,1) , (1,2) , (2,2)
Explanation 2:

 Task is impossible
*/
bool isValidPoint(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
vector<int> drow = {-1,1,0,0};
vector<int> dcol = {0,0,-1,1};
int Solution::solve(vector<vector<int> > &A) {
    int N = A.size();
    int M =A[0].size();
    int fresh = 0;
    int ans = -1;
    queue<vector<int> > q;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(A[i][j] == 2){
                q.push({i,j});  
            }
            if(A[i][j] == 1){
                fresh++;  
            }
        }
    }
    while(!q.empty()){
        int size = q.size();
        while(size--){
            vector<int> node = q.front();
            q.pop();
            
            for(int i=0; i<drow.size(); i++){
                int xp = node[0] + drow[i];
                int yp = node[1] + dcol[i];
                if(isValidPoint(xp, yp, N, M) and A[xp][yp] == 1 ){
                    A[xp][yp] = 2;
                    q.push({xp, yp});
                    fresh--;
                }
            }
        }
        ans++;
    }
    if(fresh > 0)
        return -1;
    else
        return ans;        
}
