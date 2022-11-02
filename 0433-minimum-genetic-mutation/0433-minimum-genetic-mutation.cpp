class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>vis;
        unordered_set<string>b;
        for (auto i : bank)
            b.insert(i);

        queue<string>q;
        q.push(start);
        vis.insert(start);
        char options[4] = { 'A','C','T','G' };
        int ans = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                string curr = q.front();
                q.pop();
                for (int i = 0; i < 8; i++)
                {
                    char temp = curr[i];
                    for (int j = 0; j < 4; j++)
                    {
                        curr[i] = options[j];
                        if (vis.find(curr) == vis.end() and b.find(curr) != b.end())
                        {
                            if (curr == end)return ans + 1;
                            vis.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = temp;
                }
            }
            ans++;
        }
        return -1;
    }
};