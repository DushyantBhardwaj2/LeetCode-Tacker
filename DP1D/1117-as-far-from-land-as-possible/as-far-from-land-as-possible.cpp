class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<int> dr={0,0,1,-1};
        vector<int> dc={1,-1,0,0};

        queue<pair<pair<int,int>,int>> q; // storing 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                }
            }
        }
        if(q.size()==0 || q.size()==n*m) return -1;
        int maxDis=-1;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            maxDis=max(maxDis,dist);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                    grid[nr][nc] = 1; // mark visited
                    q.push({{nr, nc}, dist + 1});
                }
            }


        }
        return maxDis;

    }
};