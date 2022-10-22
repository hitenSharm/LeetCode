class Solution {
public:
    bool checkValidString(string s) {
        //o(n) and o(n) solution is using stack and keeping track of indexes 
        //***((((** -> we need to track indexes when balancing
        //)))***(((
        
        //draw recursion tree and u will see that there is a pattern that if the the cnt value
        //(value that u wud chek if u just had '(' ')' in >=0 always)
        //lies in the range of 0- some x>0 we can have a possible solution
        
        int cmin=0,cmax=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                cmin++;
                cmax++;
            }
            if(s[i]==')')
            {
                cmin--;
                cmax--;
            }
            if(s[i]=='*')
            {
                //imp part as this decides range of answers
                //as i can either take it as ')' meaning the minimum possible value decreases or 
                //i can take it as '(' which means max possible value increases
                //this way we store the range of answers
                cmin--;
                cmax++;
            }            
            if(cmin<0)cmin=0;
            if(cmax<0)return false;
        }
        //0 shud be included in final range, dont check everytime as cases can be (((
        if(cmin<=0 and cmax>=0)return true;
        return false;
    }
};