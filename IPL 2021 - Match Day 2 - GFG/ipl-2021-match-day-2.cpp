// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> q1;
        for(int i=0; i<k; i++) {
            while(!q1.empty() and arr[q1.back()]<=arr[i]) {
                q1.pop_back();
            }
            q1.push_back(i);
        }
        vector<int> ans;
        ans.push_back(arr[q1.front()]);
        for(int i=k; i<n; i++) {
            if(!q1.empty() and i-q1.front()==k) {
                q1.pop_front();
            }
            while(!q1.empty() and arr[q1.back()]<=arr[i]) {
                q1.pop_back();
            }
            q1.push_back(i);
            ans.push_back(arr[q1.front()]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends