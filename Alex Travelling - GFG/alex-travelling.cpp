//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<int> ans(n, INT_MAX);
        ans[k-1]=0;
        vector<vector<int>> edges(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++) {
            edges[i][i]=0;
        }
        for(auto i:flights) {
            edges[i[0]-1][i[1]-1] = i[2];
        }
        bool wh=true;
        while(wh) {
            wh = false;
            for(int i=0; i<n; i++) {
                if(ans[i]!=INT_MAX) {
                    for(int j=0; j<n; j++) {
                        if(edges[i][j]!=INT_MAX) {
                            if(ans[j]>ans[i]+edges[i][j]) {
                                ans[j] = ans[i]+edges[i][j];
                                wh = true;
                            }
                        }
                    }
                }
            }
        }
        // for(auto i:ans) {
        //     cout << i << " ";
        // }
        int f_ans = 0;
        for(auto i:ans) {
            if(i==INT_MAX) return -1;
            f_ans = max(f_ans, i);
        }
        return f_ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends