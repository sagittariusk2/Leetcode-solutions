//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {

    string getStringBegining(int n) {
        string ans;
        for(int i=0; i<n; i++) {
            ans += i+'a';
        }
        return ans;
    }

    string getStringEnd(int n) {
        string ans;
        for(int i=0; i<n; i++) {
            ans += 'z'-i;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int getSum(int n) {
        int ans = 0;
        string str = to_string(n);
        for(auto i:str) {
            ans += (i-'0');
        }
        return ans;
    }

public:
    string BalancedString(int n) {
        string ans;
        int x = n;
        while(n>0) {
            if(n>=26) {
                ans += getStringBegining(13);
                ans += getStringEnd(13);
                n -= 26;
            } else {
                if(n%2==0) {
                    ans += getStringBegining(n/2);
                    ans += getStringEnd(n/2);
                } else {
                    if(getSum(x)%2==0) {
                        ans += getStringBegining((n+1)/2);
                        ans += getStringEnd((n-1)/2);
                    } else {
                        ans += getStringBegining((n-1)/2);
                        ans += getStringEnd((n+1)/2);
                    }
                }
                n=0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends