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
    typedef pair<int, int> pi;
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        // simple concept, i wanna maximise mine and the value i take from enemy
        //so add both! a put in pq
        priority_queue<pi>pq;
        int a = 0;
        int b = 0;
        int turn = 0;
        for (int i = 0; i < aliceValues.size(); i++)
        {
            pq.push({ aliceValues[i] + bobValues[i] ,i});
        }
        while (!pq.empty())
        {
            if (turn == 0)//alice
            {
                a += aliceValues[pq.top().second];
                pq.pop();
                turn = 1;
            }
            else
            {
                b += bobValues[pq.top().second];
                pq.pop();
                turn = 0;
            }
        }
        if (a == b)return 0;
        if (a > b)return 1;

        return -1;
    }
};