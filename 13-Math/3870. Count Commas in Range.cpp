1class Solution {
2public:
3    int countCommas(int n) {
4        if(n < 1e3) {
5            return 0;
6        }
7
8        return (n-1e3 + 1);
9    }
10};