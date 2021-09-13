// https://leetcode.com/problems/product-of-array-except-self

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        arrFwd=[]
        arrBwd=[]
        prodfwd=1
        arrFwd.append(1)
        
        for i in range(1,len(nums),1):
            prodfwd=prodfwd*nums[i-1]
            arrFwd.append(prodfwd)
        
        prodfwd=1
        arrBwd.append(1)
        
        for i in range(len(nums)-2,-1,-1):            
            prodfwd=prodfwd*nums[i+1]
            arrBwd.append(prodfwd)
        arrBwd.reverse()
        ans=[]                

        for i in range(0,len(nums),1):
            temp=arrFwd[i]*arrBwd[i]
            ans.append(temp)
        return ans
          
        