1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        stack<int>st;
5        int n=nums.size();
6        vector<int>ans(n,-1);
7
8        for(int i=2*n-1;i>=0;i--){
9            while(!st.empty() && st.top()<=nums[i%n]){
10                st.pop();
11            }
12            if(!st.empty() && (i<n)){
13                ans[i]=st.top();
14            }
15            st.push(nums[i%n]);
16        }
17
18        return ans;
19    }
20};