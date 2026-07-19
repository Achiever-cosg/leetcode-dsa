1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n =s.length();
5        unordered_map<char, int> mpp;
6        int left = 0, right = 0;
7
8        int maxLen = 0;
9
10        while(right < n)
11        {
12            if(mpp.find(s[right]) != mpp.end())
13            {
14                left = max(mpp[s[right]]+1, left);
15            }
16
17            mpp[s[right]] = right;
18            maxLen = max(maxLen, right - left + 1);
19
20            right++;
21        }
22
23        return maxLen;
24    }
25};