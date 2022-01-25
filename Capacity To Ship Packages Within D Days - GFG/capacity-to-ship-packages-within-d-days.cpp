// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool canCarry(int arr[], int n, int d, int mid) {
        int y=1, x=arr[0];
        for(int i=1; i<n; i++) {
            if(x+arr[i]<=mid) {
                x += arr[i];
            } else {
                y++;
                x=arr[i];
            }
        }
        return (y<=d);
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int s=*max_element(arr, arr+n);
        int e=accumulate(arr, arr+n, 0);
        int ans=-1;
        while(s<=e) {
            int mid=(s+e)/2;
            if(canCarry(arr, n, d, mid)) {
                ans=mid;
                e=mid-1;
                
            } else {
                s=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends