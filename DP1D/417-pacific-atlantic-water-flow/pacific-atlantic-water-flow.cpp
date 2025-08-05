class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> p(n,vector<int>(m,0));
        vector<vector<int>> a(n,vector<int>(m,0));

        queue<pair<int,int>> pq,aq;
        for(int i=0;i<m;i++){
            pq.push({0,i});
            aq.push({n-1,i});
            p[0][i]=1;
            a[n-1][i]=1;
        }
        for(int i=0;i<n;i++){
            pq.push({i,0});
            aq.push({i,m-1});
            p[i][0]=1;
            a[i][m-1]=1;
        }
         vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto [r, c] = pq.front();
            pq.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dirX[d];
                int nc = c + dirY[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !p[nr][nc] &&
                    heights[nr][nc] >= heights[r][c]) {
                    p[nr][nc] = true;
                    pq.push({nr, nc});
                }
            }
        }
        while (!aq.empty()) {
            auto [r, c] = aq.front();
            aq.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dirX[d];
                int nc = c + dirY[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !a[nr][nc] &&
                    heights[nr][nc] >= heights[r][c]) {
                    a[nr][nc] = true;
                    aq.push({nr, nc});
                }
            }
        }
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (p[i][j] && a[i][j])
                    result.push_back({i, j});
        
        return result;
        
        
    }
};