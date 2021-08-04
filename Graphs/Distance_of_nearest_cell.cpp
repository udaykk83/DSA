/*Distance of nearest cell
Problem Description

Given a matrix of integers A of size N x M consisting of 0 or 1.

For each cell of the matrix find the distance of nearest 1 in the matrix.

Distance between two cells (x1, y1) and (x2, y2) is defined as |x1 - x2| + |y1 - y2|.

Find and return a matrix B of size N x M which defines for each cell in A distance of nearest 1 in the matrix A.

NOTE: There is atleast one 1 is present in the matrix.



Problem Constraints
1 <= N, M <= 1000

0 <= A[i][j] <= 1



Input Format
The first argument given is the integer matrix A.



Output Format
Return the matrix B.



Example Input
Input 1:

 A = [
       [0, 0, 0, 1]
       [0, 0, 1, 1] 
       [0, 1, 1, 0]
     ]
Input 2:

 A = [
       [1, 0, 0]
       [0, 0, 0]
       [0, 0, 0]  
     ]


Example Output
Output 1:

 [ 
   [3, 2, 1, 0]
   [2, 1, 0, 0]
   [1, 0, 0, 1]   
 ]
Output 2:

 [
   [0, 1, 2]
   [1, 2, 3]
   [2, 3, 4] 
 ]


Example Explanation
Explanation 1:

 A[0][0], A[0][1], A[0][2] will be nearest to A[0][3].
 A[1][0], A[1][1] will be nearest to A[1][2].
 A[2][0] will be nearest to A[2][1] and A[2][3] will be nearest to A[2][2].
Explanation 2:

 There is only a single 1. Fill the distance from that 1.
   */
   
bool isValidPoint(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
vector<int> drow = {-1,1,0,0};
vector<int> dcol = {0,0,-1,1};
vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    int N = A.size();
    int M =A[0].size();
    vector<vector<int>> ans(N, vector<int>(M,-1));
    //vector<vector<int>> vis(N*M, vector<int>(N*M,0));
    queue<vector<int> > q;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(A[i][j] == 1){
                q.push({i,j,0});
                ans[i][j] = 0;  
            }
        }
    }
    while(!q.empty()){
       vector<int> node = q.front();
        q.pop();
            for(int i=0; i<drow.size(); i++){
                int xp = node[0] + drow[i];
                int yp = node[1] + dcol[i];
                if(isValidPoint(xp, yp, N, M) and A[xp][yp] == 0 and ans[xp][yp] == -1 ){
                    ans[xp][yp] = node[2] + 1;
                    q.push({xp, yp, (node[2] + 1)});
                }
            }
    }
    return ans;        
}
