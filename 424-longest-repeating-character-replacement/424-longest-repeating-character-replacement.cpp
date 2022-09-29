class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        unordered_map<char, int>ump;
        int ans = 0;
        while (i < s.size())
        {
            while (j < s.size())
            {
                ump[s[j]]++;                
                int freq = 0;
                int maxiFreq = 0;
                for (auto it : ump)
                {
                    maxiFreq = max(maxiFreq, it.second);
                    freq += it.second;
                }
                freq -= maxiFreq;//largest ke alawa ke saare that can be changed
                if (freq > k){
                    ump[s[j]]--;
                    break;
                }
                j++;
            }
            ans = max(ans, j - i);
            ump[s[i]]--;
            if (ump[s[i] == 0])ump.erase(s[i]);
            i++;
        }
        return ans;
    }
};