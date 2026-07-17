1class Solution {
2public:
3    vector<int> par, edgeCount, nodeCount;
4    int find(int i){
5        if(par[i] == -1) return i;
6        return find(par[i]);
7    }
8    
9    void unionPair(int a, int b ){
10        int pa = find(a), pb = find(b);
11        edgeCount[pa] += 1;
12        if(pa != pb){
13            par[pb] = pa;
14            edgeCount[pa] += edgeCount[pb];
15            nodeCount[pa] += nodeCount[pb];
16        }
17    }
18    int countCompleteComponents(int n, vector<vector<int>>& edges) {
19        int ans = 0;
20        par.resize(n, -1);   edgeCount.resize(n, 0);    nodeCount.resize(n, 1);
21        for(auto e: edges) unionPair(e[0], e[1]);
22        for(int i = 0; i < n; ++i){
23            if(nodeCount[i] && par[i] == -1  && ( nodeCount[i] * (nodeCount[i] - 1)/2 == edgeCount[i] ) ) ans++;
24        }
25        return ans;
26    }
27};