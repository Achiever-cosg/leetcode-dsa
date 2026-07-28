1class Solution {
2private:
3    bool areEqual(vector<int>& v, vector<int>& v2)
4    {
5        for(int i=0; i<26; i++)
6        {
7            if(v[i] != v2[i])
8                return false;
9        }
10
11        return true;
12    }
13
14public:
15    bool checkInclusion(string s1, string s2) {
16        int left = 0, right = 0;
17        vector<int> v(27, 0);
18        for(auto c: s1)
19            v[c-'a']++;
20
21        vector<int> v2(27, 0);
22
23        while(right < s2.length())
24        {
25            v2[s2[right]-'a']++;
26            if(right-left+1 == s1.length())
27            {
28                if(areEqual(v, v2))
29                    return true;
30
31                v2[s2[left]-'a']--;
32                left++;
33            }
34            right++;
35        }
36
37        return false;
38    }
39};