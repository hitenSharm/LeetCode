// https://leetcode.com/problems/distant-barcodes

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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int>ump;
        int freqMax=INT_MIN;
        int valFreqMax=0;
        
        for(int i=0;i<barcodes.size();i++)
        {
            ump[barcodes[i]]++;
            if(ump[barcodes[i]]>freqMax)
            {
                freqMax=ump[barcodes[i]];
                valFreqMax=barcodes[i];
            }
        }
        int curr=0;
        while(freqMax>0 and curr<barcodes.size())
        {
            barcodes[curr]=valFreqMax;
            freqMax--;
            curr+=2;
        }
        curr=1;
        ump.erase(valFreqMax);
        
        for(auto i:ump)
        {
            int tmp=i.first;
            int val=i.second;
            while(curr<barcodes.size() and val>0)
            {
                barcodes[curr]=tmp;
                val--;
            }
        }
        return barcodes;
    }
};