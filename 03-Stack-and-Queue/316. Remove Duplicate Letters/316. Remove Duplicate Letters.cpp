1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4        vector<int> lastIndex(26, 0);
5        for (int i = 0; i < s.length(); i++){
6            lastIndex[s[i] - 'a'] = i; 
7        }
8        
9        vector<bool> seen(26, false); 
10        stack<char> st;
11        
12        for (int i = 0; i < s.size(); i++) {
13            int curr = s[i] - 'a';
14            if (seen[curr]) continue; 
15            while(st.size() > 0 && st.top() > s[i] && i < lastIndex[st.top() - 'a']){
16                seen[st.top() - 'a'] = false;
17                st.pop();
18            }
19            st.push(s[i]); 
20            seen[curr] = true;
21        }
22        
23        string ans = ;
24        while (st.size() > 0){
25            ans += st.top();
26            st.pop();
27        }
28        reverse(ans.begin(), ans.end());
29        return ans;
30    }
31};