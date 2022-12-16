//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    
    bool valid(int i, int j, int n, int m) {
        return (i>=0 and j>=0 and i<n and j<m);
    }
    
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        int x1_even[] = {-1, -1, -1, 0, 1, 0};
        int y1_even[] = {-1, 0, 1, 1, 0, -1};
        
        int x1_odd[] = {0, -1, 0, 1, 1, 1};
        int y1_odd[] = {-1, 0, 1, 1, 0, -1};
        
        int x2_even[] = {-2, -2, -2, -1, 0, 1, 1, 2, 1, 1, 0, -1};
        int y2_even[] = {-1, 0, 1, 2, 2, 2, 1, 0, -1, -2, -2, -2};
        
        int x2_odd[] = {-2, -1, -1, 0, 1, 2, 2, 2, 1, 0, -1, -1};
        int y2_odd[] = {0, 1, 2, 2, 2, 1, 0, -1, -2, -2, -2, -1};
        // code here
        int ans=0;
        if(ty==0) {
            if(j%2==1) {
                for(int a=0; a<6; a++) {
                    if(valid(i+x1_odd[a], j+y1_odd[a], n, m)) {
                        ans += mat[i+x1_odd[a]][j+y1_odd[a]];
                    }
                }
            } else {
                for(int a=0; a<6; a++) {
                    if(valid(i+x1_even[a], j+y1_even[a], n, m)) {
                        ans += mat[i+x1_even[a]][j+y1_even[a]];
                    }
                }
            }
        } else {
            if(j%2==1) {
                for(int a=0; a<12; a++) {
                    if(valid(i+x2_odd[a], j+y2_odd[a], n, m)) {
                        ans += mat[i+x2_odd[a]][j+y2_odd[a]];
                    }
                }
            } else {
                for(int a=0; a<12; a++) {
                    if(valid(i+x2_even[a], j+y2_even[a], n, m)) {
                        ans += mat[i+x2_even[a]][j+y2_even[a]];
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends