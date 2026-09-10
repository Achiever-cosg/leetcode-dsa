1class Solution {
2private:
3    bool isValid(int i, int n) {
4        return i >= 0 && i < n;
5    }
6public:
7    int orangesRotting(vector<vector<int>>& grid) {
8        int m = grid.size();
9        int n = grid[0].size();
10        int freshCnt = 0;
11        vector<vector<bool>> vis(m, vector<bool>(n, false));
12        queue<pair<int, int>> q;
13        int delrow[] = {-1, 0, 1, 0};
14        int delcol[] = {0, 1, 0, -1};
15
16        for(int i=0; i<m; i++) {
17            for(int j=0; j<n; j++) {
18                if(grid[i][j] == 2) {
19                    q.push({i, j});
20                    vis[i][j] = true;
21                }
22
23                if(grid[i][j] == 1) {
24                    freshCnt++;
25                }
26            }
27        }
28
29        int time = 0;
30        while(!q.empty()) {
31            int size = q.size();
32            bool hasRotten = false;
33
34            for(int i=0; i<size; i++) {
35                auto it = q.front();
36                q.pop();
37                
38                int row = it.first;
39                int col = it.second;
40
41                for(int k=0; k<4; k++) {
42                    int nrow = row + delrow[k];
43                    int ncol = col + delcol[k];
44
45                    if(isValid(nrow, m) && isValid(ncol, n) && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
46                        freshCnt--;
47                        vis[nrow][ncol] = true;
48                        q.push({nrow, ncol});
49                        hasRotten = true;
50                    }
51                }
52            }
53
54            if(hasRotten) 
55                time++;
56        }
57
58        return freshCnt == 0 ? time : -1;
59    }
60};