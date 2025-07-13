class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mpp;
        for(auto trip : trips){
            int start=trip[1];
            int end=trip[2];
            while(start<end){
                mpp[start]+=trip[0];
                if(mpp[start]>capacity) return false;
                start++;
            }
        }
        return true;
        
    }
};