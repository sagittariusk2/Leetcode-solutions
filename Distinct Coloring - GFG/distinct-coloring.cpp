//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        long long int a1=r[N-1], b1=g[N-1], c1=b[N-1];
        for(int i=N-2; i>=0; i--) {
            long long int a2=r[i]+min(b1, c1);
            long long int b2=g[i]+min(c1, a1);
            long long int c2=b[i]+min(a1, b1);
            a1=a2;
            b1=b2;
            c1=c2;
        }
        return min(min(a1, b1), c1);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends