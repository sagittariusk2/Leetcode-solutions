//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution {
public:

    vector<int> getPrime(int n) {
        vector<bool> p(n+1, true);
        p[0] = p[1] = false;
        for(int i=2; i<=n; i++) {
            if(p[i]) {
                for(int j=i+i; j<=n; j+=i) {
                    p[j] = false;
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<=n; i++) {
            if(p[i]) ans.push_back(i);
        }
        return ans;
    }
    
    vector<int> threeDivisors(vector<long long> query, int q){
        long long mx = LLONG_MIN;
        for(auto i:query) {
            mx = max(mx, i);
        }
        mx = sqrt(mx);
        vector<int> prime = getPrime(mx);
        vector<int> ans;
        for(auto i:query) {
            ans.push_back(upper_bound(prime.begin(), prime.end(), (int)sqrt(i))-prime.begin());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends