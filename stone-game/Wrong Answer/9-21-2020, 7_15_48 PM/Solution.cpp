// https://leetcode.com/problems/stone-game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int al=0,cl=0;
        int i=0;
        int j=piles.size()-1;
        char curr='a';
        while(i<j)
        { 
            if(curr=='a')
            { 
                if(piles[i]==piles[j])
                {
                    i++;
                    j--;
                    curr='a';
                    continue;
                }
                
                al=al+max(piles[i],piles[j]);
                
                if(piles[i]>piles[j])
                {
                    i++;
                    curr='c';
                    continue;
                }
                if(piles[j]>piles[i])
                {
                    j--;
                    curr='c';
                    continue;
                }
                
            }
            if(curr=='c')
            { 
                if(piles[i]==piles[j])
                {
                    i++;
                    j--;
                    curr='c';
                    continue;
                }
                
                cl=cl+max(piles[i],piles[j]);
                
                if(piles[i]>piles[j])
                {
                    i++;
                    curr='a';
                    continue;
                }
                if(piles[j]>piles[i])
                {
                    j--;
                    curr='a';
                    continue;
                }
                
            }
            if(i>=j)
                break;
        }
        if(i==j)
        {
              if(curr=='a')
              { 
                al=al+piles[i];
              }
              else
              { 
                cl=cl+piles[i];
              }
        }
        
        cout<<al<<" "<<cl;
        
        if(al>cl)return true;
        
        return false;
    }
};