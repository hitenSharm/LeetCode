class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        
        //tc: o(log(min(m,n)));
        
        int n=nums1.size()+nums2.size();
        int l=0;
        int r=nums1.size();
        
        while(l<=r)
        {
            int cut1=l+(r-l)/2;
            int cut2=((n+1)/2) - cut1;
            
            //cut signifies the number of elements NOT the index
            
            int lu = cut1==0 ? INT_MIN : nums1[cut1-1]; //nums 1 ka left
            int ld = cut2==0 ? INT_MIN : nums2[cut2-1]; //nums 2 ka left
            
            int ru = cut1==nums1.size() ? INT_MAX : nums1[cut1];
            int rd = cut2==nums2.size() ? INT_MAX : nums2[cut2];
            
            if(lu<=rd and ld<=ru)
            {
                if(n%2==0)
                {
                    return (max(lu,ld)+min(ru,rd))/2.0;
                }
                return max(lu,ld);
            }
            else if(lu>rd)
            {
                r=cut1-1;
                //go back in first array as this element cant be taken
            }
            else
                l=cut1+1;
            
        }
        return 0.0;
    }
};