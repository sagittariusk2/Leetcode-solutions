// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
public:
    long long countStrings(string S) {
        // code here
        int a[26] = {0};
        int sum = S.length();
        long long ans = 0;
        for(auto i:S) {
            a[i-'a']++;
            if(a[i-'a']>1) ans = 1;
        }
        for(auto i:S) {
            ans += (sum-a[i-'a']);
            sum --;
            a[i-'a']--;
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends