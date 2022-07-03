class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        vector<int>pre(height.size());
        vector<int>post(height.size());
        pre[0]=height[0];
        post[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++)
        {
            pre[i]=max(pre[i-1],height[i]);            
        }        
        for(int i=height.size()-2;i>=0;i--)
            post[i]=max(post[i+1],height[i]);
        for(int i=1;i<height.size()-1;i++)
        {
            int h=min(pre[i-1],post[i+1]);            
            if(h>height[i])
            ans+=h-height[i];
        }
        return ans;
    }
};