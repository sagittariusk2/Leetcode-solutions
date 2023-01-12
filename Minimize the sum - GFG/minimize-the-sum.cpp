//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++
// 36 -> 111   4+7+10+14+18+23+29+36
class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        multiset<int> st;
        for(auto i:arr) {
            st.insert(i);
        }
        int ans=0;
        while(st.size()!=1) {
            int x = *st.begin();
            st.erase(st.begin());
            int y = *st.begin();
            st.erase(st.begin());
            int z = x+y;
            ans += z;
            st.insert(z);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends