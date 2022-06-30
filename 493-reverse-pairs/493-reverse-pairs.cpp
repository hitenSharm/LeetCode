class Solution {
public:

    int cnt=0;    
    
    void merging(vector<int>& nums,int l,int m,int r)
    {
        
        int j=m+1;
        for(int i=l;i<=m;i++)
        {
            while(j<=r and nums[i]>2*(long)nums[j])
                j++;
            
            cnt+=(j-(m+1));
        }
        
        vector<int>t1;vector<int>t2;
        for(int i=l;i<=m;i++)
        {
            t1.push_back(nums[i]);
        }
        for(int i=m+1;i<=r;i++)
        {
            t2.push_back(nums[i]);
        }                        
        int sub1=0,sub2=0;
        int ni=l;
        while(sub1<t1.size() and sub2<t2.size())
        {
            nums[ni]=min(t1[sub1],t2[sub2]);
            if(nums[ni]==t1[sub1])sub1++;
            else
            sub2++;
            
            ni++;
        }
        while(sub1<t1.size())
        {
            nums[ni]=t1[sub1];
            sub1++;ni++;
        }
        while(sub2<t2.size())
        {
            nums[ni]=t2[sub2];
            sub2++;ni++;
        }
    }
    
    void mergeSort(vector<int>& nums,int l,int r)
    {
        if(l>=r)return ;
        int m=l+(r-l)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,r);
        merging(nums,l,m,r);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);        
        return cnt;
    }
};