class SparseVector {

private:
    vector<pair<int, int>>arr;

public:
    SparseVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)continue;
            arr.push_back({ i,nums[i] });
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        vector<pair<int, int>> arr2 = vec.arr;
        int i = 0;
        int j = 0;
        int ans = 0;
        while (i < arr.size() and j<arr2.size())
        {
            if (arr[i].first == arr2[j].first)
            {
                ans += (arr[i].second * arr2[j].second);
                i++;
                j++;
            }
            else if (arr[i].first < arr2[j].first)
            {
                i++;
            }
            else
                j++;
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);