// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    public:
    bool valid(int i, int j, int n) {
        return (i>0 and j>0 and i<=n and j<=n);
    }
    
    int x1[8]={-2, -2, -1, -1, 1, 1, 2, 2};
    int y1[8]={1, -1, -2, 2, 2, -2, -1, 1};
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n) {
	    // Code here
	    queue<vector<int>> qu;
	    qu.push(KnightPos);
	    vector<vector<int>> vis(n+1, vector<int> (n+1, 0));
	    int ans = 0;
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    while(!qu.empty()) {
	        queue<vector<int>> q2;
	        int c=0;
	        while(!qu.empty()) {
	            for(int i=0; i<8; i++) {
	                if(valid(qu.front()[0]+x1[i], qu.front()[1]+y1[i], n) and vis[qu.front()[0]+x1[i]][qu.front()[1]+y1[i]]==0) {
	                    c = 1;
	                    vector<int> x(2);
	                    x[0] = qu.front()[0]+x1[i];
	                    x[1] = qu.front()[1]+y1[i];
	                    vis[qu.front()[0]+x1[i]][qu.front()[1]+y1[i]]=1;
	                    if(x[0] == TargetPos[0] and x[1] == TargetPos[1]) return ans+c;
	                    q2.push(x);
	                }
	            }
	            qu.pop();
	        }
	        ans+=c;
	        qu = q2;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends