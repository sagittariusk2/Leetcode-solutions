#User function Template for python3
class Solution:

	# Function to find maximum
	# product subarray
	def maxProduct(self,arr, n):
		# code here
		mx, mn, ans=arr[0],arr[0],arr[0]
		for i in range(n-1):
		    x,y=mx,mn
		    mx=max(arr[i+1], x*arr[i+1], y*arr[i+1])
		    mn=min(arr[i+1], x*arr[i+1], y*arr[i+1])
		    ans=max(ans, mx)
		return ans

#{ 
#  Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends