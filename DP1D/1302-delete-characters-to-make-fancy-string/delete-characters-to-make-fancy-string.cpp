class Solution {
public:
    string makeFancyString(string s) {
        bool del=false;
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            
            if(s[i]==s[i-1] && !del) {
                del=true;
                ans+=s[i];
            }
            if(s[i]!=s[i-1]){
                ans+=s[i];
                del=false;

            }
        }
        return ans;
        
    }
};