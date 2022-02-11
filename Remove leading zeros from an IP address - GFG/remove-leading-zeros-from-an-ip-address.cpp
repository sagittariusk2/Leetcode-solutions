// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution {
public:
    string newIPAdd (string s) {
        //code here.
        string x, ans;
        for(auto i:s) {
            if(i=='.') {
                int j=0;
                for(j=0; j<x.size()-1; j++) {
                    if(x[j]!='0') break;
                }
                ans += x.substr(j);
                ans += '.';
                x = "";
            } else {
                x += i;
            }
        }
        int j=0;
        for(j=0; j<x.size()-1; j++) {
            if(x[j]!='0') break;
        }
        ans += x.substr(j);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends