class Solution {
public:
    bool checkGood(string word){
        int n=word.size()-1;
        if((word[0]=='a' || word[0]=='e'|| word[0]=='i'||word[0]=='o' ||word[0]=='u') && (word[n]=='a' || word[n]=='e'|| word[n]=='i'||word[n]=='o' ||word[n]=='u')) return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> prefix(n);
        int sum=0;
        for(int i=0;i<n;i++){
            if(checkGood(words[i])){
                sum++;
            }
            prefix[i]=sum;
        }
        vector<int> ans;
        for(auto t : queries){
            int temp=prefix[t[1]]-prefix[t[0]];
            if(checkGood(words[t[0]])) temp++;
            ans.push_back(temp);
        }
        return ans;
    }
};