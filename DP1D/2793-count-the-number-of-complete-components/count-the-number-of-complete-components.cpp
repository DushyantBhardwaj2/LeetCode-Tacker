class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //create adj lis
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        // make all connected component
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> temp;
                queue<int> p;
                p.push(i);
                vis[i]=1;
                while(!p.empty()){
                    int node=p.front();
                    p.pop();
                    temp.push_back(node);
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            p.push(it);
                            vis[it]=1;
                        }
                    }
                }
                // check for each component that it is complete 
                bool complete=true;
                for(int j=0;j<temp.size();j++){
                    
                    if(adj[temp[j]].size()!= temp.size()-1){
                        complete=false;
                        break;
                    }
                }

                if(complete) ans++;
            }
            

        }
        return ans;;
        
        
        
    }
};