class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //3x3 valididty check ke liye 2 for loops
        //i=0;i<9;i+=3
            //j=0;j<9;j+=3
                //end of 3x3 grid i+2,j+2 i,j se i+2,j+2 mein ek loop to check
        //ek col wise valid
        //ek row wise valid
        //this is not a greate method
        //--------------------------------------------------
        //simply think, we need to check rowwise,colwise and gridwise
        //can i calculate the grid of any number based on index
        //yes if we see grid like 1(3x3) 2(3x3) 3(3x3)
        //                        4(3x3) ........
        //we can make formular (row/3)*3 and col/3 to get grid number
        //now use a string hasemap and store col and numbers as col + colNumber + number
        //so any number in col that gets repeated gets found by hashmap
        
        unordered_set<string>ust;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')continue ;
                string rowString = "row"+to_string(i)+board[i][j];
                string colString = "col"+to_string(j)+board[i][j];
                int boxNumber = (i/3)*3 + j/3;                
                string boxString = "box" + to_string(boxNumber) + board[i][j];
                if(ust.find(rowString)!=ust.end() || ust.find(colString)!=ust.end() || ust.find(boxString)!=ust.end())return false;
                ust.insert(rowString);
                ust.insert(colString);
                ust.insert(boxString);
            }
        }
        return true;
    }
};