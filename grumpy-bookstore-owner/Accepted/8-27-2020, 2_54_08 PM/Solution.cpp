// https://leetcode.com/problems/grumpy-bookstore-owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans=0;
        int reans=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans=ans+customers[i];
            }
        }
        
        for(int i=0;i<X;i++){
            if(grumpy[i]==1){
                ans=ans+customers[i];
            }
        }
        reans=ans;
        int j=0;
        for(int i=X;i<n;i++){
            
            if(grumpy[j]==1){
                ans=ans-customers[j]; 
                cout<<j<<" j \n";
            }
            j++;
            if(grumpy[i]==1){
                ans=ans+customers[i];
                //cout<<i<<" j\n";
                reans=max(ans,reans);
            }
            
        }
        
        
       return reans; 
    }
};