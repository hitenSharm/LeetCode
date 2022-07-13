class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size();
        int n2=version2.size();
        int i=0,j=0;
        
        while(i<n1 || j<n2)
        {
            int number1=0;
            int number2=0;
            while(i<version1.size() and version1[i]!='.')
            {
                number1=(number1*10)+(version1[i]-'0');
                i++;
            }
            while(j<version2.size() and version2[j]!='.')
            {
                number2=(number2*10)+(version2[j]-'0');
                j++;
            }
            if(number1>number2)return 1;
            if(number2>number1)return -1;
            
            i++;j++;
        }
        return 0;
    }
};