class SparseVector {

private:
    unordered_map<int, int>arr;

public:
    SparseVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)continue;
            arr[i] = nums[i];
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        unordered_map<int, int>ump=vec.arr;
        int ans = 0;
        for (auto it : arr)
        {            
            ans += (it.second * ump[it.first]);
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);