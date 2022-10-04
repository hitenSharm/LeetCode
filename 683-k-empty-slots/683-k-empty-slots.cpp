class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int>st;
        for(int i=0;i<bulbs.size();i++)
        {
            st.insert(bulbs[i]);
            if(st.find(bulbs[i]-k-1)!=st.end())
            {
                int val=bulbs[i]-k-1;
                if(*st.upper_bound(val) == bulbs[i])return i+1;
            }
            if(st.find(bulbs[i]+k+1)!=st.end())
            {
                int val=bulbs[i];
                if(*st.upper_bound(val) == bulbs[i]+k+1)return i+1;
            }
        }
        return -1;
    }
};