1class Solution {
2private:
3    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
4        if(j == t.length()) {
5            return 1;
6        }
7
8        if(i == s.length()) {
9            return 0;
10        }
11
12        if(dp[i][j] != -1) {
13            return dp[i][j];
14        }
15
16        if(s[i] == t[j]) {
17            int take = solve(i+1, j+1, s, t, dp);
18            int skip = solve(i+1, j, s, t, dp);
19
20            return dp[i][j] = take + skip;
21        }
22
23        return dp[i][j] = solve(i+1, j, s, t, dp);
24    }
25public:
26    int numDistinct(string s, string t) {
27        int m = s.length();
28        int n = t.length();
29
30        vector<vector<int>> dp(m, vector<int>(m, -1));
31        int ans = solve(0, 0, s, t, dp);
32
33        return ans;
34    }
35};