class Solution {
public:
    int nthUglyNumber(int n) {
        int i=0,j=0,k=0;
        vector<int>arr(1,1);
        while(arr.size()<1691)
        {
            int newEle=min(arr[i]*2,min(arr[j]*3,arr[k]*5));
            if(newEle==arr[i]*2)i++;
            if(newEle==arr[j]*3)j++;
            if(newEle==arr[k]*5)k++;
            arr.push_back(newEle);
        }
        return arr[n-1];
    }
};