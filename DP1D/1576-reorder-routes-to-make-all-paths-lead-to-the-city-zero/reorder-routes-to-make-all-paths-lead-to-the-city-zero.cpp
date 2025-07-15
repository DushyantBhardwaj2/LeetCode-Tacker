class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        set<pair<int,int>> real;
        queue<int> pq;
        vector<int> vis(n,0);
        pq.push(0);
        vis[0]=1;
        
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            real.insert({it[0],it[1]});
        }
        int ans=0;
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            for(int x : adj[node]){
                if(!vis[x]){
                    pq.push(x);
                    vis[x]=1;
                    if(real.count({node,x})){
                    ans++;
                     }
                }
                
            }
        }
        return ans;


        
    }
};