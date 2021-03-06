// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K){
    queue<long long> q1;
    vector<long long> ans;
    for(long long i=0; i<K; i++) {
        if(A[i]<0) q1.push(i);
    }
    if(q1.empty()) ans.push_back(0);
    else ans.push_back(A[q1.front()]);
    for(long long i=K; i<N; i++) {
        if(!q1.empty() and i-K==q1.front()) q1.pop();
        if(A[i]<0) q1.push(i);
        if(q1.empty()) ans.push_back(0);
        else ans.push_back(A[q1.front()]);
    }
    return ans;
}