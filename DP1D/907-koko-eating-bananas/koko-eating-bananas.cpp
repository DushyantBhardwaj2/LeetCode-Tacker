class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int end=*max_element(piles.begin(),piles.end());
        int start=1;
        int ans=end;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            long long count=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid>0) count++;
                count+=(long long)piles[i]/mid;
            }
            if(count>h){
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
        
    }
};