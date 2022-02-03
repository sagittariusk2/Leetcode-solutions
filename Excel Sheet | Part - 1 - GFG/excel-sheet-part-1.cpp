// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    string ExcelColumn(int N) {
        // Your code goes here
        string ans ="";
        while(N>0) {
            int r = N%26;
            if(r==0) r += 26;
            char x = r+'A'-1;
            ans += x;
            N /= 26;
            if(r==26) N--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends