1class Solution {
2public:
3    int n, m;
4    vector<int> delrow = {-1, 0, 1, 0};
5    vector<int> delcol = {0, -1, 0, 1};
6
7    bool isValid(int i, int n) {
8        return i >= 0 && i<n;
9    }
10
11    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int& area) {
12        vis[row][col] = 1;
13
14        for(int k=0; k<delrow.size(); k++) {
15            int nrow = row + delrow[k];
16            int ncol = col + delcol[k];
17
18            if(isValid(nrow, m) && isValid(ncol, n) && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
19                dfs(nrow, ncol, grid, vis, ++area);
20            }
21        }
22    }
23
24    int maxAreaOfIsland(vector<vector<int>>& grid) {
25        m = grid.size();
26        n = grid[0].size();
27
28        int maxArea = 0;
29        vector<vector<int>> vis(m, vector<int>(n, 0));
30        
31        for(int i=0; i<m; i++) {
32            for(int j=0; j<n; j++) {
33                if(grid[i][j] == 1 && vis[i][j] == 0) {
34                    int area = 1;
35                    dfs(i, j, grid, vis, area);
36
37                    maxArea = max(maxArea, area);
38                }
39            }
40        }
41
42        return maxArea;
43    }
44};