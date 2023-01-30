//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool solve(vector<set<int>> &edg, vector<bool> &v1, int root) {
        if(!edg[root].empty()) {
            bool ans=true;
            for(auto i:edg[root]) {
                edg[i].erase(root);
                ans=(ans & (solve(edg, v1, i)));
            }
            return v1[root]=!ans;
        }
        return v1[root]=false;
    }
    int countVertex(int n, vector<vector<int>>edges){
        vector<bool> v1(n, false);
        vector<set<int>> edg(n);
        for(auto i:edges) {
            edg[i[0]-1].insert(i[1]-1);
            edg[i[1]-1].insert(i[0]-1);
        }
        solve(edg, v1, 0);
        int ans = 0;
        for(auto i:v1) {
            // cout << i << " ";
            if(i) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends