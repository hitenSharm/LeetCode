class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& pic) {
        vector<int>top(pic[0].size(), 0);
        vector<int>left(pic.size(), 0);
        for (int i = 0; i < pic.size(); i++)
        {
            for (int j = 0; j < pic[0].size(); j++)
            {
                if (pic[i][j] == 'B')
                {
                    top[j]++;
                    left[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < pic.size(); i++)
        {
            for (int j = 0; j < pic[0].size(); j++)
            {
                if (pic[i][j] == 'B' and top[j]==1 and left[i]==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};