1class Solution 
2{
3public:
4    int minScore(int n, vector<vector<int>>& roads) 
5    {
6        vector<pair<int, int>> adj[n+1];
7        for(int i=0; i<roads.size(); i++)
8        {
9            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
10            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
11        }
12         
13        vector<int> vis(n+1, 0);
14        queue<int> q;
15        q.push(1), vis[1]=1;
16        while(!q.empty())
17        {
18            int node=q.front();
19            q.pop();
20            for(auto it: adj[node])
21            {
22                if(!vis[it.first])
23                {
24                    q.push(it.first);
25                    vis[it.first]=1;
26                }
27            }
28        }
29            
30        int mini_path = INT_MAX;
31        for(int i=0; i<roads.size(); i++)
32        {
33            if(vis[roads[i][0]] && vis[roads[i][1]] && roads[i][2] < mini_path)
34                mini_path = roads[i][2];
35        }
36        return mini_path;
37        
38    }
39};