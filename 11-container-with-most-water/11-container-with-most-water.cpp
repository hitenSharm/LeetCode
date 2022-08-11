class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int area=0;
        while(l<=r)
        {
            area=max(min(height[l],height[r])*(r-l),area);
            if(min(height[l],height[r])==height[l])l++;
            else
                r--;
        }
        return area;
            
    }
};