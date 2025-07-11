class Solution {
public:
    bool f(int ind1,int ind2,int ind3,string& s1, string& s2, string& s3,vector<vector<vector<int>>>& dp){
        if(ind3==s3.size()) return true;
        if(dp[ind1][ind2][ind3]!=-1) return dp[ind1][ind2][ind3];
        bool st1=false;
        if(ind1<s1.size() && s3[ind3]==s1[ind1]){
            st1=f(ind1+1,ind2,ind3+1,s1,s2,s3,dp);
        }
        bool st2=false;
        if(ind2<s2.size() && s3[ind3]==s2[ind2]){
            st2=f(ind1,ind2+1,ind3+1,s1,s2,s3,dp);
        }
        return dp[ind1][ind2][ind3]= st1 | st2;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return f(0,0,0,s1,s2,s3,dp);
        
        
    }
};