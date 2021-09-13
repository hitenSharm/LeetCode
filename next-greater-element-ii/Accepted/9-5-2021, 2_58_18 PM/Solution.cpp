// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        stack<int>st;
        int cnt=0;
        for(int i=0;cnt<2*nums.size();i=(i+1)%nums.size(),cnt++)
        {
            while(!st.empty() and nums[st.top()]<nums[i])
            {
                int& tmp=st.top();
                ans[tmp]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};