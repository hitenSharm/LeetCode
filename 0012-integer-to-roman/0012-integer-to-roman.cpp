class Solution {
public:
    string intToRoman(int num) {
        string ump[]={
          "M","CM","D","CD","C","XC","L","XL","X","IX","VII","V","IV","I"
        };
        int vals[]={1000,900,500,400,100,90,50,40,10,9,7,5,4,1};
        string ans="";
        for(int i=0;i<=13;i++)
        {
            while(vals[i]<=num)
            {
                ans+=ump[i];
                num-=vals[i];
            }
        }
        return ans;
    }
};