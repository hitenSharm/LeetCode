class Solution {
public:
    bool isPossible(vector<int>& nums) {
        //at each point i saw if i could either make it into a subseq of 3 nums
        //if i cant i tried to chek if there exists a subseq b4r me that i can be a part of
        //if i find one we do it
        unordered_map<int,int>freq;
        unordered_map<int,int>ends;
        for(auto i:nums)freq[i]++;
        
        for(auto i:nums)
        {
            if(freq[i]==0)continue ;
            if(ends[i-1]>0)//some seq already exists which has lengthe 3 and i cant make a new one from me so i become a part of that
            {
                ends[i-1]--;
                freq[i]--;
                ends[i]++;//now it ends with me
            }
            else if(freq[i+1]>0 and freq[i+2]>0)
            {
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                //a 3 len sub sequ which ends with i+2
                ends[i+2]++;
            }            
            else
                return false;
        }
        return true;
        
    }
};