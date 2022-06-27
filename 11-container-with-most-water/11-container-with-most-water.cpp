class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int area=0;
        // https://leetcode.com/problems/container-with-most-water/discuss/200246/Proof-by-formula
        //jis side pe height kam hai,udhar obv fir height for all possible cases fix ho jayegi
        //and agar mein width kam karta toh obv area will become lesser
        while(i!=j)
        {
            area=max(area,min(height[i],height[j])*(j-i));
            if(min(height[i],height[j])==height[i])i++;
            else
            j--;
        }
        return area;
    }
};