// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    
    int x2[8]={-1, -1, -1, 0, 0, 1, 1, 1};
    int y2[8]={-1, 0, 1, 1, -1, -1, 0, 1};
    
    bool valid(int i, int j, int n, int m) {
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    
    void solve(vector<vector<int>> &visited, vector<vector<char>>& grid, int i, int j, int n, int m) {
        if(valid(i, j, n, m) && visited[i][j]==-1 && grid[i][j]=='1') {
            visited[i][j]=1;
            for(int k=0; k<8; k++) {
                solve(visited, grid, i+x2[k], j+y2[k], n, m);
            }
        }
    }
    
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        vector<vector<int>> visited(n, vector<int> (m, -1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1' && visited[i][j]==-1) {
                    ans++;
                    solve(visited, grid, i, j, n, m);
                }
                visited[i][j]=1;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends