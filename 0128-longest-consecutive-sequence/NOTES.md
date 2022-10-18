```
class Solution {
public:
int recu(vector<int>& dp,unordered_map<int,int>& ump,int element)
{
int index=ump[element];
if(dp[index]!=-1)return dp[index];
int ans=1;
if(ump.find(element+1)!=ump.end())
{
ans+=recu(dp,ump,element+1);
}
//this way i am just going fwd and if that element has explored all possobo=iliteis ahead of itself
//i can return it
return dp[index]=ans;
//what i say is, lets say i am at 3. i get a count of all that come after 3
//now say i reach 1 in for loop. when i get to 3 i can simply return the count from 3
//giving me the largest possible length
//i am visiting an element at most once, o(n)
//neet codes solution is o(2n)
}
int longestConsecutive(vector<int>& nums) {
vector<int>dp(nums.size(),-1);
unordered_map<int,int>ump;
for(int i=0;i<nums.size();i++)ump[nums[i]]=i;
int ans=0;
for(int i=0;i<nums.size();i++)
{
ans=max(ans,recu(dp,ump,nums[i]));
}
return ans;
}
};
```