1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        int n = s.length();
5        int midPos = 0;
6        if(n & 1) {
7            midPos = n/2;
8        }
9
10        // base cases
11        if(n <= 3)
12            return s;
13
14        vector<int> freq(26, 0);
15        for(char c: s) {
16            freq[c-'a']++;
17        }
18
19        vector<char> res(n);
20        int currInd = 0;
21        for(int i=0; i<26; i++) {
22            int f = freq[i];
23            if(f) {
24                char c = 'a' + i;
25                if(f & 1) {
26                    res[midPos] = c;
27                }
28
29                for(int j=0; j<f/2; j++) {
30                    res[currInd] = c;
31                    res[n-currInd-1] = c;
32                    currInd++;
33                }
34            }
35        }
36
37        string ans = ;
38        for(char c: res) {
39            // cout<<c<< ;
40            ans += c;
41        }
42
43        return ans;
44    }
45};