// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) { 
        string ans;
        int n=S.size();
        for(int i=n-1; i>=0; i--) {
            int x=0;
            while(i>=0 && S[i]!='.') {
                x++;
                i--;
            }
            if(ans.size()!=0) ans += '.';
            ans += S.substr(i+1, x);
        }
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends