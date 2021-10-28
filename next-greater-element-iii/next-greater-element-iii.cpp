class Solution {
public:
    string IntToString(int a)
    {
        ostringstream temp;
        temp << a;
        return temp.str();
    }
    int nextGreaterElement(int n) {        
        string s=IntToString(n);
        long long tmp;
        if(next_permutation(s.begin(),s.end()))
            tmp=stoll(s);
        else
            return -1;
        // cout<<log2(tmp);
        if(log2(tmp)<31)return tmp;
        return -1;        
    }
};