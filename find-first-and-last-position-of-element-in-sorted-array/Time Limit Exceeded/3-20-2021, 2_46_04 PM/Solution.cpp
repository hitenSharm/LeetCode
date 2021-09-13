// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int binarySearch(vector<int>& arr, int l, int r, int x) 
    { 
        while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
    } 
  
    vector<int> searchRange(vector<int>& nums, int target) {
        int minIndex=nums.size()-1;
        int maxIndex=0;
        int fl=0;
        int tempIndex=binarySearch(nums,0,nums.size()-1,target);
        if(tempIndex==-1)
        {
            minIndex=-1;
            maxIndex=-1;
            fl=1;
        }
        else
        {
            minIndex=min(minIndex,tempIndex);
            maxIndex=max(maxIndex,tempIndex);
        }
        int t1=tempIndex;
        int t2=tempIndex;       
        //cout<<t1<<" "<<t2;
        while(fl==0)
        {
            if(t1-1>=0 && t1!=-1)
            {
                t1=binarySearch(nums,0,t1-1,target);
            }
            if(t2+1<nums.size() && t2!=-1)
            {
                t2=binarySearch(nums,t2+1,nums.size()-1,target);
            }
            if(t1==-1 && t2==-1)
            {
                fl=1;
                break;
            }
            
            if(t1>=0)
            minIndex=min(t1,minIndex);
            if(t2<nums.size())
            maxIndex=max(t2,maxIndex);
        }
        vector<int>ans;
        ans.push_back(minIndex);
        ans.push_back(maxIndex);
        return ans;
    }
};