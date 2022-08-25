// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //n*randn +randn - n gives uniform in 1-n^2
       //rand n*rand n is not uniform as the prob for numbers like 5 is less than 36
        int x=7*rand7() + rand7() -7;
        //so as i want 10, last multiple of 10 in range 1-49 is a uniform distribution
        if(x<=40)
            return x%10+1;
        
        return rand10();
    }
};