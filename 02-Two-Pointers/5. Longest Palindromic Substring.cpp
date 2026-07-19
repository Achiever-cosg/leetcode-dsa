class Solution {
public:
    int left=0;
    int right=0;
    int length=INT_MIN;
    void checkPalindrome(string s , int start, int end)
    {
           while(start>=0 and end<s.size())
           {
               if(s[start]!=s[end])
               {
                   break;
               }
               start--;
               end++;
           }
            end--;
            start++;
           int tempLen= end-start+1;
           if(tempLen>length)
           {
               left=start;
               right= end;
               length=tempLen;
           }

           return ;
    }
