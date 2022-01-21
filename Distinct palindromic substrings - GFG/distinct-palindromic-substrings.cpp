// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
public:
    int palindromeSubStrs(string s) {
        set<string> s1;
        int n = s.length();
        // odd length palindrome string
        for(int i=0; i<n; i++) {
            int j=i, k=i, x=-1;
            while(j>=0 and k<n) {
                if(s[j]!=s[k]) break;
                else {
                    x += 2;
                    s1.insert(s.substr(j, x));
                    j--, k++;
                }
            }
        }
        
        // even length palindrome string
        for(int i=1; i<n; i++) {
            int j=i-1, k=i, x=0;
            while(j>=0 and k<n) {
                if(s[j]!=s[k]) break;
                else {
                    x += 2;
                    s1.insert(s.substr(j, x));
                    j--, k++;
                }
            }
        }
        
        return s1.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends