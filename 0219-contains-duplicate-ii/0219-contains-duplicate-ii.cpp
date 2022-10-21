class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>ust;
        int i=0,j=0;
        while(i<nums.size())
        {
            while(j<nums.size() and j-i<=k)
            {
                if(ust.find(nums[j])!=ust.end())return true;
                ust.insert(nums[j]);
                j++;
            }
            ust.erase(nums[i]);
            i++;
        }
        return false;
    }
};