class Solution {
public:
    
    int getLower(int x,vector<int>& temp)
    {
        int l=0,r=temp.size()-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(temp[m]>=x)
                r=m-1;
            else
                l=m+1;
        }
        return l;
    }
    
    int lengthOfLIS(vector<int>& arr) {
        vector<int>temp;
        temp.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>temp.back())temp.push_back(arr[i]);//increaseing the length
            else
            {
                int index=getLower(arr[i],temp);
                temp[index]=arr[i]; //replace element
            }
        }
        return temp.size();
    }
};