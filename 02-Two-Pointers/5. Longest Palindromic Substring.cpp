1class Solution {
2public:
3    int left=0;
4    int right=0;
5    int length=INT_MIN;
6    void checkPalindrome(string s , int start, int end)
7    {
8           while(start>=0 and end<s.size())
9           {
10               if(s[start]!=s[end])
11               {
12                   break;
13               }
14               start--;
15               end++;
16           }
17            end--;
18            start++;
19           int tempLen= end-start+1;
20           if(tempLen>length)
21           {
22               left=start;
23               right= end;
24               length=tempLen;
25           }
26
27           return ;
28    }
29
30    string iterative(string s, int start, int end)
31    {
32           int n= s.size();
33
34           for(int i=0;i<n;i++)
35           {
36               checkPalindrome(s,i,i);
37               checkPalindrome(s,i,i+1);
38           }
39        //   cout<<left<<" "<<right<<endl;
40         return s.substr(left,length);
41    }
42    string longestPalindrome(string s) {
43        
44
45        int n= s.size();
46        left=0;
47        right=0;
48        length=INT_MIN;
49
50        string ans= iterative(s,0,n);
51
52        return ans;
53    }
54};