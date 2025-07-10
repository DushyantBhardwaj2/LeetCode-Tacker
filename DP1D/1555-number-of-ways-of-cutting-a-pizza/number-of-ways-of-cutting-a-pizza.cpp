class Solution {
public:
int MOD=1e9+7;
    int f(int r,int c,int k,int m,int n,vector<vector<int>>& apples, vector<vector<vector<int>>>& dp){
        if(apples[r][c]==0) return 0;
        if(k==0) return 1;
        if (dp[k][r][c] != -1) return dp[k][r][c];
        int cut=0;
        for(int nr=r+1;nr<m;nr++){
            if(apples[r][c] - apples[nr][c] > 0){
                cut=(cut+f(nr,c,k-1,m,n,apples,dp))%MOD;
            }
        }
        for(int nc=c+1;nc<n;nc++){
            if(apples[r][c] - apples[r][nc] > 0){
                cut=(cut+f(r,nc,k-1,m,n,apples,dp))%MOD;
            }
        }
        dp[k][r][c]=cut;
        return cut;

    }
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size();
        int n=pizza[0].size();
        vector<vector<int>> apples(m+1,vector<int>(n+1,0));
        
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                apples[i][j]=(pizza[i][j]=='A')+ apples[i+1][j]+apples[i][j+1]-apples[i+1][j+1];
            }
        }
        vector<vector<vector<int>>> dp(k,vector<vector<int>> (m+1,vector<int>(n+1,-1)));
        
        return f(0,0,k-1,m,n,apples,dp);
    }
};