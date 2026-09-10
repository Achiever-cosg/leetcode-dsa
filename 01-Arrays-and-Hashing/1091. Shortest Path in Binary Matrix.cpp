1class Solution {
2private:
3    bool isValid(int i, int n) {
4        return i >= 0 && i < n;
5    }
6public:
7    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
8        int m = grid.size();
9        int n = grid[0].size();
10        vector<int> dirs = {-1, 0, 1};
11
12        if(grid[0][0] == 1)
13            return -1;
14        vector<vector<int>> vis(m, vector<int>(n, 0));
15        queue<pair<pair<int, int>, int>> q;
16        q.push({{0, 0}, 1});
17        vis[0][0] = 1;
18
19        while(!q.empty()) {
20            int size = q.size();
21            for(int i=0; i<size; i++) {
22                auto it = q.front();
23                q.pop();
24
25                int row = it.first.first;
26                int col = it.first.second;
27                int dist = it.second;
28
29                if(row == m-1 && col == n-1) {
30                    return dist;
31                }
32
33                for(int i=0; i<3; i++) {
34                    for(int j=0; j<3; j++) {
35                        int nrow = row + dirs[i];
36                        int ncol = col + dirs[j];
37
38                        if(isValid(nrow, m) && isValid(ncol, n) && grid[nrow][ncol] == 0 && !vis[nrow][ncol]) {
39                            vis[nrow][ncol] = 1;
40                            q.push({{nrow, ncol}, dist+1});
41                        }
42                    }
43                }
44            }
45        }
46
47        return -1;
48    }
49};