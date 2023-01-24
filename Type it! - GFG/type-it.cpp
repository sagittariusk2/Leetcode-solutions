//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int ans = 0;
        int n=s.size();
        bool used = false;
        for(int i=n-1; i>=0; i--) {
            if(i%2 and !used) {
                int x = (i+1)/2;
                if(s.substr(0, x)==s.substr(x, x)) {
                    i=x;
                    used = true;
                }
            }
            ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends