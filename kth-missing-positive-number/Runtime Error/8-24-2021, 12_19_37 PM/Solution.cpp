// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi=1;
        if(arr.size()==1)
        {
            k=k-(arr[0]-maxi);                 
            if(k<=0)return (0+(k+(arr[0]-maxi)));
            else
            return arr[arr.size()-1]+k;
        }
        for(int i=0;i<arr.size();i++)
        {            
            if(arr[i]!=maxi)
            {
              k=k-(arr[i]-maxi);                 
              if(k<=0)return (arr[i-1]+(k+(arr[i]-maxi)));
            }
            maxi=arr[i]+1;
        }
        return arr[arr.size()-1]+k;
    }
};