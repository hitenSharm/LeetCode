class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        //approach 1
        //if mat elements were just 0,1 make all 0 in matrix -1
        //then loop again and for each -1 make row,col=0
        //tc : o(m*n)+(m+n) sc:o(1)
        //similar to approach 1, if mat elements can be anything
        //stroe another array marking elements u need to be 0. o(mn) space
        //approach 2
        //have 2 sets, iterate, if 0 , add that row and col to sets
        //iterate again, if either row or col is in set, make mat[i][j]=0
        //tc: o(m*n) sc:o(m+n)
        
        //app 3:
        //see neetcodes vid,
        // basically, ik that there will be overlapping at 0,0 if i tyr and use the extra m+n arrays inside the matrix
        //so to deal with that i create antoehr element which tells the col wether it's supposed to be 0 or not
        //elements in col 0 check with the extra element if it needs to be turned into a 0 & elements in row 1 check with 0,0
        bool makeCol=false;
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][0]==0)makeCol=true;
            for(int j=1;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }   
        for(int i=mat.size()-1;i>=0;i--)
        {
            for(int j=mat[i].size()-1;j>=1;j--)
                if(mat[i][0]==0 || mat[0][j]==0)mat[i][j]=0;
            if(makeCol)mat[i][0]=0;
        }
        
    }
};