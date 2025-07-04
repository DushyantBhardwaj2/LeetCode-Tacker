class Solution {
public:

    int f(int ind,int target,vector<vector<int>>& dp){
        if (target==0) return 0;
        
        if(ind == 1) return target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int take=1e9;
        if(target - ind*ind >= 0){
            take=1+f(ind,target - ind*ind ,dp);
        }
        int notTake=f(ind-1,target,dp);
        return dp[ind][target]=min(take,notTake);
    }

    int numSquares(int n) {

        int nums=sqrt(n);
        vector<vector<int>> dp(nums+1, vector<int>(n+1,-1));
        return f(nums,n,dp);
        
        
    }
};