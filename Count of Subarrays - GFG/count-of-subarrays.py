#User function Template for python3
class Solution:


	def countSubarray(self,arr, n, k):
	    res=n*(n+1)//2
	    ans=0
	    cnt=0
	    for i in range(0,n):
	        if arr[i]<=k:
	            cnt=cnt+1
	        else:
	            ans=ans+(cnt*(cnt+1)//2)
	            cnt=0
	    ans=ans+(cnt*(cnt+1)//2)
	    return res-ans
	    


#{ 
 # Driver Code Starts
#Initial Template for Python 3


# Driver code 
if __name__ == "__main__": 		
    tc=int(input())
    while tc > 0:
        n, k=map(int, input().strip().split())
        arr=list(map(int, input().strip().split()))
        ob = Solution()
        ans=ob.countSubarray(arr, n, k)
        print(ans)
        tc=tc-1
# } Driver Code Ends