class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1) return ans;
        ans.push_back({1,1});
        if(numRows==2) return ans;
        
       
        for(int j=3;j<=numRows;j++){
            vector<int> temp(j,0);
            temp[0]=1;
            temp[j-1]=1;
            for(int i=1;i<j-1;i++){
                temp[i]=ans[j-2][i-1]+ans[j-2][i];
            }
            ans.push_back(temp);
        }
        return ans;  
    }
};