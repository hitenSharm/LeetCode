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
//                        4(3x3) ........
//we can make formular (row+1)%3 and col/3 to get grid number
//now use a string hasemap and store col and numbers as col + colNumber + number
//so any number in col that gets repeated gets found by hashmap
https://www.youtube.com/watch?v=rJ9NFK9s_mI