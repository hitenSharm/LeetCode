class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int farthestEnd=0;
        int endHere=0;
        for(int i=0;i<nums.size();i++)
        {
            int canTravel=i+nums[i];
            farthestEnd=max(farthestEnd,canTravel);
            if(i==endHere)
            {
                if(i!=nums.size()-1)
                ans++;
                endHere=farthestEnd;
            }
        }
        return ans;
    }
};