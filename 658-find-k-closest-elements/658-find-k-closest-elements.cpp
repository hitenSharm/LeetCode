class Solution {
public:

    int getIndex(vector<int>& arr,int& x)
    {
        int l=0,r=arr.size()-1;
        int diff=INT_MAX;
        int ans;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int temp=arr[m];
            if(abs(temp-x)<=diff)
            {
                if(diff==abs(temp-x))ans=min(ans,m);
                else
                    ans=m;
                diff=abs(temp-x);                
            }
            if(arr[m]>x)
                r=m-1;
            else
            {                
                l=m+1;
            }
        }
        return ans;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx=getIndex(arr,x);
        int i=idx-1;
        int j=idx+1;
        vector<int>ans;
        k--;
        ans.push_back(arr[idx]);
        while(k--)
        {
            if(i>=0 and j<arr.size())
            {
                if(abs(arr[i]-x)>abs(arr[j]-x))
                {
                    ans.push_back(arr[j]);
                    j++;
                }
                else
                {
                    ans.push_back(arr[i]);
                    i--;
                }
            }
            else if(i>=0)
            {
                ans.push_back(arr[i]);
                i--;
            }
            else if(j<arr.size())
            {
                ans.push_back(arr[j]);
                j++;
            }
                
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};