class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            int target = (-1) * nums[i];
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    ans.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]>target){
                    r--;
                }
                else if(nums[l]+nums[r]<target){
                    l++;
                }
            }
        }
        vector<vector<int>> result;
        for (auto x : ans)
            result.push_back(x);
        return result;
    }
};