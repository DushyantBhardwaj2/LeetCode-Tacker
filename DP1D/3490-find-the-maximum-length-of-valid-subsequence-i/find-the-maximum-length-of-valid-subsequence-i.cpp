class Solution {
public:
    
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int odd=0;
        int diff=nums[0]&1;
        int len=1;
        for(int i=0;i<n;i++){
            if(nums[i]&1) odd++;
            if((nums[i]&1)!=diff){
                len++;
                diff=(nums[i]&1);
            }
        }
        odd=max(odd,n-odd);
        return max(odd,len);

        
    }
};