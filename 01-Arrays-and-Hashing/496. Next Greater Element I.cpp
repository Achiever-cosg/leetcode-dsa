1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        stack<int> stk;
5        reverse(nums2.begin(), nums2.end());
6        vector<int> res(nums1.size(), -1);
7        unordered_map<int, int> mpp;
8
9        for(int num: nums2) {
10            while(stk.size() > 0 && stk.top() < num) {
11                stk.pop();
12            }
13            if(stk.size() == 0) {
14                mpp[num] = -1;
15            } else {
16                mpp[num] = stk.top();
17            }
18            stk.push(num);
19        }
20
21        for(int i=0; i<nums1.size(); i++) {
22            if(mpp[nums1[i]]) {
23                res[i] = mpp[nums1[i]];
24            }
25        }
26
27        return res;
28    }
29};