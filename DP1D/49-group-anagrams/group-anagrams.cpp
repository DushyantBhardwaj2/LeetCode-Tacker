class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp= strs;
        for(int i=0;i<temp.size();i++){
            sort(temp[i].begin(),temp[i].end());
        }
         vector<vector<string>> ans;
        vector<bool> vis(strs.size(),false);
        for(int i=0;i<strs.size();i++){
            if(!vis[i]){
                vector<string> y;
                string x=temp[i];
                for(int j=i;j<strs.size();j++){
                    if(temp[j]==x){
                        vis[j]=true;
                        y.push_back(strs[j]);
                    }
                }
                ans.push_back(y);
            }
        }
        return ans;
    }
};