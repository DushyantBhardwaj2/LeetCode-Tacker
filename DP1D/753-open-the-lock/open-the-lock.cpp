class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        unordered_set<string> st(deadends.begin(),deadends.end());
        if(st.count("0000")) return -1;
        if(target == "0000") return 0;

        q.push({"0000",0});
        unordered_set<string> visit;
        visit.insert("0000");
        while(!q.empty()){
            string s=q.front().first;
            int level=q.front().second;
            q.pop();
            
            if(s==target) return level;
            for(int i=0;i<s.size();i++){
                char ow=s[i];
                s[i] = (ow == '9') ? '0' : ow + 1;
                if(s == target) return level + 1;
                if(!st.count(s) && !visit.count(s)){
                    visit.insert(s);
                    q.push({s, level + 1});
                }
                s[i] = (ow == '0') ? '9' : ow - 1;
                if(s == target) return level + 1;
                if(!st.count(s) && !visit.count(s)){
                    visit.insert(s);
                    q.push({s, level + 1});
                }
                s[i]=ow;
            }
        }
        return -1;
        
    }
};