class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(arr[m-1]>arr[m] and arr[m]>arr[m+1])r=m;
            else if(arr[m-1]<arr[m] and arr[m]<arr[m+1])l=m+1;
            if(arr[m]>arr[m-1] and arr[m]>arr[m+1])return m;
        }
        return -1;
    }
};