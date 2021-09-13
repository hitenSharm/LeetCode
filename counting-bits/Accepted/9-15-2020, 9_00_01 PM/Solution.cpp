// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>re;
        for(int i=0;i<=num;i++)
        { 
            re.push_back(__builtin_popcount(i));
        }
        return re;
    }
};