// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	int minDistance(vector<int> &dist, vector<bool> &sptSet) {
	    int mn=INT_MAX, mn_index;
	    for(int i=0; i<dist.size(); i++) {
	        if(sptSet[i]==false and dist[i]<=mn) {
	            mn = dist[i], mn_index=i;
	        }
	    }
	    return mn_index;
	}
	
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<vector<int>> graph(V, vector<int>(V, 0));
        for(int i=0; i<V; i++) {
            for(auto j:adj[i]) {
                graph[i][j[0]]=j[1];
                // cout << i << ", " << j[0] << " : " << j[1] << endl;
            }
        }
        
        // Code here
        vector<int> ans(V, INT_MAX);
        ans[S]=0;
        vector<bool> sptSet(V, false);
        
        for(int i=0; i<V-1; i++) {
            int j = minDistance(ans, sptSet);
            sptSet[j]=true;
            for(int k=0; k<V; k++) {
                if(!sptSet[k] and graph[j][k] and ans[j]!=INT_MAX and ans[j]+graph[j][k]<ans[k]) {
                    ans[k] = ans[j]+graph[j][k];
                }
            }
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends