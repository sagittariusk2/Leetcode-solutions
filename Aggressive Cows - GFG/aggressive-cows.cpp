//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool feasible(int mid, vector<int> &stalls, int k) {
        int cow = 1, pos = stalls[0];
        for(int i=1; i<stalls.size(); i++) {
            if(stalls[i]-pos>=mid) {
                cow++;
                pos = stalls[i];
            }
        }
        return cow>=k;
    }

    int solve(int n, int k, vector<int> &stalls) {
        int mn = INT_MAX, mx = INT_MIN;
        sort(stalls.begin(), stalls.end());
        for(int i=1; i<n; i++) {
            mn = min(mn, stalls[i]-stalls[i-1]);
            mx = max(mx, max(stalls[i], stalls[i-1]));
        }
        int ans = mx;
        while(mn<mx) {
            int mid = (mn+mx)/2;
            if(feasible(mid, stalls, k)) {
                mn = mid+1;
                ans = mid;
            } else {
                mx = mid;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends