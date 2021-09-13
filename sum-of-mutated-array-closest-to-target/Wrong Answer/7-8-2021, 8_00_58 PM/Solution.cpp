// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:

    int findSum(vector<int>& arr,int m)
    {
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>m)
            ans+=m;
            else
            ans+=arr[i];
        }
        return ans;
    }

    int findBestValue(vector<int>& arr, int target) {
        int l=1,r=100000;
        int value=INT_MAX;int sumClosest=findSum(arr,INT_MAX);
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int tempSum=findSum(arr,m);
            if(tempSum==target)
            {
                value=min(value,m);
                sumClosest=target;
                r=m-1;
                continue;
            }
            if(tempSum>target)
            {
                r=m-1;
                if((abs(tempSum-target)<abs(sumClosest-target)) || (abs(tempSum-target)==abs(sumClosest-target) and m<value))
                {
                    value=m;
                    sumClosest=tempSum;
                }
                continue;
            }
            else
            {
                l=m+1;
                if((abs(tempSum-target)<abs(sumClosest-target)) || (abs(tempSum-target)==abs(sumClosest-target) and m<value))
                {
                    value=m;
                    sumClosest=tempSum;
                }
            }
        }
        return value;
    }
};