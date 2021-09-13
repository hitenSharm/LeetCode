// https://leetcode.com/problems/grumpy-bookstore-owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans=0;
        int reans=0;
        int n=customers.size();
        for(int i=0,j=0;i<n;i++){
            
            while(j<n){
                
                while(X>0 && j<n){
                    ans=ans+customers[j];
                    j++;
                    X--;
                }
                
                reans=max(reans,ans);
                if(j>=n)
                    break;
                
                if((grumpy[j]==0)&& j<n){ 
                    ans=ans+customers[j];
                    j++;
                    reans=max(reans,ans);
                    continue;
                }
                if((grumpy[j]==1) && j<n){ 
                    break;
                }
                
            }
           
            ans=ans-customers[i];
             X++;
            if(ans<0){
                ans=0;
            }
                
          
               
        }   
        return reans;
        
        
    }
};