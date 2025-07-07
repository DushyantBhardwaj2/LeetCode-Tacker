class Solution {
public:
    int f(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp,int&  m,int& n){
        if(col==n-1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int maxMove=0;
        if(row-1>=0 && col+1<=n-1 && grid[row-1][col+1]>grid[row][col]){
            maxMove=max(1+f(row-1,col+1,grid,dp,m,n),maxMove);
        }
        if(col+1<=n-1 && grid[row][col+1]>grid[row][col]){
            maxMove=max(1+f(row,col+1,grid,dp,m,n),maxMove);
        }
        if(row+1<=m-1 && col+1<=n-1 && grid[row+1][col+1]>grid[row][col]){
            maxMove=max(1+f(row+1,col+1,grid,dp,m,n),maxMove);            
        }
        return dp[row][col]=maxMove;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,f(i,0,grid,dp,m,n));

        }
        return ans;
        
    }
};