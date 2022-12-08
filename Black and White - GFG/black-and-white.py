#User function Template for python3


#Function to find out the number of ways we can place a black and a white
#Knight on this chessboard such that they cannot attack each other.
def numOfWays(M, N):
    MOD = 10**9 + 7
    attacking = 0
    for i in range(M):
        for j in range(N):
            for di, dj in [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < M and 0 <= nj < N:
                    attacking += 1
                    
    total = (M*N)*(M*N-1)
    return  (total - attacking)%MOD


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        m,n = map(int,input().strip().split())
        print(numOfWays(m,n))

# } Driver Code Ends