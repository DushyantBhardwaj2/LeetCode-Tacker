class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int n=0;
        while(num!=0){
            if((num & 1)==1){
                n++;
                num=num>>1;
            }
            else{
                ans=ans | (1<<n);
                n++;
                num=num>>1;
            }
            
        }
        return ans;
        
    }
};