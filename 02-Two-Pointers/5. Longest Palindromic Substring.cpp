class Solution {
public:
int left=0;
int right=0;
int length=INT_MIN;
void checkPalindrome(string s , int start, int end)
{
while(start>=0 and end<s.size())
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
int tempLen= end-start+1;
if(tempLen>length)
{
left=start;
right= end;
length=tempLen;
}
return ;
}
string iterative(string s, int start, int end)
{
int n= s.size();
for(int i=0;i<n;i++)
{
checkPalindrome(s,i,i);
checkPalindrome(s,i,i+1);
}
//   cout<<left<<" "<<right<<endl;
return s.substr(left,length);
}
string longestPalindrome(string s) {
int n= s.size();
left=0;
right=0;
length=INT_MIN;
string ans= iterative(s,0,n);
return ans;
}
};