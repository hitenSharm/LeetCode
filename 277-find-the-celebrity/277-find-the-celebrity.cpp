/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    
    bool isCeleb(int& x,int& n)
    {
        for(int i=0;i<n;i++)
        {
            if(i==x)continue ;
            if(!knows(i,x) || knows(x,i))return false;
        }
        return true;
    }
    
    int findCelebrity(int n) {
        //o(n^2) chek for each person if they are known by every1 but dont know any1
        //if a knows b => a isnt a celeb but b could be
        //if a doesent know b => a COULD be a celeb
        int candidate=0;
        for(int i=0;i<n;i++)
        {
            if(knows(candidate,i))
            {
                //candidate knows i => candidate isnt a celeb but 'i' could be
                candidate=i;
            }
        }
        if(isCeleb(candidate,n))return candidate;
        return -1;
    }
};