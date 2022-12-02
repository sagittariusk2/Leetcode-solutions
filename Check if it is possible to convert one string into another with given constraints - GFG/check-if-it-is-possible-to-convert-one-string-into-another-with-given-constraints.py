#User function Template for python3

class Solution:
    def isItPossible(sef, S, T, M, N):
        #code here
        s = ""
        t = ""
        for i in S:
            if i!='#':
                s += i
        for i in T:
            if i!='#':
                t += i
        if s==t:
            return 1
        return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        S,T=input().split()
        ob=Solution()
        print(ob.isItPossible(S,T,len(S),len(T)))
# } Driver Code Ends