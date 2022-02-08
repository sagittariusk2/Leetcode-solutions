// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> primeRange(int m, int n) {
        vector<int> prime;
        vector<bool> p((long long)n+1, true);
        if(n<2) return prime;
        for(int i=2; i<=n; i++) {
            if(p[i]) {
                prime.push_back(i);
                for(int j=i; j<=n; j+=i) {
                    p[j]=false;
                }
            }
        }
        int i = lower_bound(prime.begin(), prime.end(), m)-prime.begin();
        vector<int> ans;
        for(int j=i; j<prime.size(); j++) {
            ans.push_back(prime[j]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends