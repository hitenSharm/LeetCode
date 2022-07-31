class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0;
        int cnt10=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)cnt5++;
            else if(bills[i]==10)
            {
                if(cnt5<=0)return false;
                cnt5--;
                cnt10++;
            }
            else
            {                
                if(cnt10>=1 and cnt5>=1)
                {
                    cnt10--;cnt5--;
                }
                else if(cnt5>=3)
                {
                    cnt5-=3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};