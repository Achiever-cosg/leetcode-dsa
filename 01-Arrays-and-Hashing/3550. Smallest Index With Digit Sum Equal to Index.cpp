1class Solution {
2private:
3    bool isTrue(int num, int index) {
4        int sum = 0;
5        while(num > 0) {
6            sum += num%10;
7            num /= 10;
8        }
9
10        return sum == index;
11    }
12
13public:
14    int smallestIndex(vector<int>& nums) {
15        int n = nums.size();
16
17        for(int i=0; i<n; i++) {
18            if(isTrue(nums[i], i)) {
19                return i;
20            }
21        }
22
23        return -1;
24    }
25};