class Solution {
public:

    int fl=0;    
    void pushing(vector<vector<int>>& mat,int i,int j,vector<int>& arr)
    {
         if(fl==0)
        {
            int sm=(mat.size()-i-1 > j ? j:mat.size()-i-1);
            int ti=i+sm;
            int tj=j-sm;
            while(ti>=0 and tj<mat[0].size())
            {
                arr.push_back(mat[ti][tj]);
                ti--;
                tj++;
            }
            fl=1;
        }
        else
        {
            int ti=i,tj=j;
            while(tj>=0 and ti<mat.size())
            {
                arr.push_back(mat[ti][tj]);
                tj--;
                ti++;
            }
            fl=0;
        }
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>arr;
        int i=0,j=0;        
        for(j=0;j<mat[0].size();j++)
        {
            pushing(mat,i,j,arr);
        }
        i=1;
        j--;
        while(i<mat.size())
        {
            pushing(mat,i,j,arr);
            i++;
        }
        return arr;
    }
};