class Solution:

    #Function to find distance of nearest 1 in the grid for each cell.
	def nearest(self, grid):
        ans = []
		n = len(grid)
		m = len(grid[0])
		for i in range(n):
            temp = []
            for j in range(m):
                temp.append(1000000)
            ans.append(temp)
        
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1:
                    ans[i][j] = 0
                else:
                    if i==0 and j==0:
                        pass
                    elif i==0:
                        ans[i][j] = min(ans[i][j], ans[i][j-1])+1
                    elif j==0:
                        ans[i][j] = min(ans[i][j], ans[i-1][j])+1
                    else:
                        ans[i][j] = min(ans[i-1][j], ans[i][j-1])+1
                        
        for a in range(n):
            for b in range(m):
                i = n-a-1
                j = m-b-1
                if grid[i][j]==1:
                    ans[i][j] = 0
                else:
                    if i==n-1 and j==m-1:
                        pass
                    elif i==n-1:
                        ans[i][j] = min(ans[i][j], ans[i][j+1]+1)
                    elif j==m-1:
                        ans[i][j] = min(ans[i][j], ans[i+1][j]+1)
                    else:
                        ans[i][j] = min(ans[i][j], min(ans[i+1][j], ans[i][j+1])+1)
        
        return ans


#{ 
 # Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n, m = map(int, input().split())
		grid = []
		for _ in range(n):
			a = list(map(int, input().split()))
			grid.append(a)
		obj = Solution()
		ans = obj.nearest(grid)
		for i in ans:
			for j in i:
				print(j, end = " ")
			print()

# } Driver Code Ends