class Solution {
public:
    int MOD=1e9+7;
    int f(int ind,int fuel, int finish,vector<int>& locations,vector<vector<int>>& dp){
        if(fuel==0){
            return ind==finish;
        }
        if(dp[ind][fuel]!=-1) return dp[ind][fuel];
        int totalWay=0;
        if(ind==finish) totalWay=1;
        for(int j=0;j<locations.size();j++){
            if(abs(locations[ind] - locations[j])<=fuel && ind!=j){
                int temp=f(j,fuel-abs(locations[ind] - locations[j]),finish,locations,dp);
                totalWay=(totalWay+temp)%MOD;
            }
        }
        return dp[ind][fuel]=totalWay;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(),vector<int> (fuel+1,-1));
        return f(start,fuel,finish,locations,dp);
    }
};