// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    string longestCommonPrefix (string arr[], int N) {
        int x=arr[0].size();
        for(int i=1; i<N; i++) {
            int t=0;
            for(int j=0; j<arr[i].size() and arr[i][j]==arr[0][j]; j++) t++;
            x = min(x, t);
        }
        if(x==0) return "-1";
        return arr[0].substr(0, x);
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends