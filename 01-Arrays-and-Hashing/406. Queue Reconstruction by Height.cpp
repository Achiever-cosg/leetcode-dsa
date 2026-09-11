1class Solution {
2public:
3    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
4        sort(people.begin(), people.end(), cmp);
5        vector<vector<int>> res(people.size(), vector<int>());
6        for(int i = 0; i < people.size(); i++){
7            int cnt, j;
8            for(cnt = 0, j = 0; j < res.size(); j++){ //empty count start from 0
9                if(res[j].empty()){
10                    if(cnt==people[i][1]) break;
11                    cnt++;
12                }
13            }
14            res[j]=people[i];
15        }
16        return res;
17    }
18    static bool cmp(vector<int>& p1, vector<int>& p2){
19        if(p1[0]!=p2[0]) return p1[0]<p2[0];
20        else return p1[1]>p2[1];
21    }
22};