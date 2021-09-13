// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    
    int findPivot(vector<int>& nums)
    {
        int l=0;
        int r=nums.size()-1;
        int piv;        
        while(l<r){ 
           int mid=l + (r - l)/2;
            if(nums[mid+1]<nums[mid])
                return mid;
           if(nums[mid]>nums[l])
           {
               l=mid;
           }
            else
            {
                r=mid;
            }
        }
        return 0;
    }
    int binarySearch(vector<int>& arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        
        if (arr[mid] == x) 
            return mid; 
  
        
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
       
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    
    return -1; 
} 
  
    
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int piv=findPivot(nums);
        int ans1=binarySearch(nums,0,piv,target);
        int ans2=binarySearch(nums,piv+1,nums.size()-1,target);
        return max(ans1,ans2);
    }
};