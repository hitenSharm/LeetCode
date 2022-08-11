class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner=arr[0];
        int wins=0;
        for(int i=1;i<arr.size();i++)
        {
            if(winner>arr[i])
                wins++;
            else
            {
                wins=1;
                winner=arr[i];
            }
            if(wins==k)return winner;
        }
        return *max_element(arr.begin(),arr.end());
    }
};