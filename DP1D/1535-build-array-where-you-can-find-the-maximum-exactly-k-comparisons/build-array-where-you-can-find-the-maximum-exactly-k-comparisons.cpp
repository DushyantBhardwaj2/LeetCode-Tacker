class Solution {
public:
int dp[51][51][101];
int MOD=1e9+7;
int f(int k,int size,int prev,int n,int m ){
    if(size==n){
        return k==0;
    }
    if(k<0) return 0;
   if(dp[k][size][prev]!=-1) return dp[k][size][prev];
    int total=0;
    for(int i=1;i<=m;i++){
        if(i>prev){
            total=(total+f(k-1,size+1,i,n,m))%MOD;
        }
        else{
            total=(total+f(k,size+1,prev,n,m))%MOD;
        }
    }
    return dp[k][size][prev]=total;

}
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return f(k,0,0,n,m);
    }
};