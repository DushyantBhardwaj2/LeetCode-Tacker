class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        vector<int> dr={0,1,-1,0};
        vector<int> dc={-1,0,0,1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto pair = q.front();
                        q.pop();
                        int r=pair.first;
                        int c=pair.second;
                        for(int i=0;i<4;i++){
                            int nr=r+dr[i];
                            int nc=c+dc[i];
                            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]=='1' ){
                                q.push({nr,nc});
                                vis[nr][nc]=1;
                            }
                        }
                    }
                }
            }
        }
        return count;



        
    }
};