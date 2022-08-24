class Solution {
public:
    bool isPowerOfThree(int n) {
        // if(n==0)return false;
        // int x=log2(n)/log2(3);
        // return pow(3,x)==n;
        
        //while loop each n=n/3 and n%3==0
        
        //for any prime, the largest pssible power of it is 
        //a*a*a*a*a.....
        //so if the largest power of a is divisible by n, it is a power of a
        //non prime mein wont work, take 6 for example, 6^x cud be 2^a*3^b
        //but for 2^x,3^x,5^x its always prime*prime*prime*prime ...
        //any power is always like this
        //so largest power is prime*prime*prime*prime.... and any n is also prime*prime*prime 
        //so just divide
        return n > 0 && 1162261467 % n == 0;
    }
};