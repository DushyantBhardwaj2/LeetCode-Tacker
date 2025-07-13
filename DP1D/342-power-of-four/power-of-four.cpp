class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        while(n!=0){
           
            if((n&1)==1){
                n>>=1;
                if(n!=0) return false;
                else return true;
            }
            n>>=1;
           
            if((n&1)==1){
                return false;
            }
            n>>=1;
        }
        return true;
    }
};