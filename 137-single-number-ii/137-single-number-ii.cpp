class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int ans=0;
        unsigned int shift=1;
        for(int i=0;i<32;i++)
        {
            int cnt=0;
            for(auto i:nums)
            {
                if(i & shift)cnt++;//is 1 at tha position
            }
            if(cnt%3!=0)ans+=shift;//add at that position
            
            //as if bits are set at that position we need if a bit is set it must repeat 3 times.
            //so if any bit which is set isnt a multiple of 3 => it is in the answer
            
            shift<<=1; //1 -> 2 -> 4 -> ........
        }
        return ans;
    }
};