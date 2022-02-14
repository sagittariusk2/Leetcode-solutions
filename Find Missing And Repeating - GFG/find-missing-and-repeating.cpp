// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        
        long long sum=0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }
        
        for(int i=0; i<n; i++) {
            int x = arr[i];
            while(arr[x-1]!=0) {
                int y = arr[x-1];
                arr[x-1]=0;
                x = y;
            }
        }
        for(int i=0; i<n; i++) {
            if(arr[i]!=0) {
                ans[1] = i+1;
                break;
            }
        }
        long long x = sum+(long long)ans[1]-((long long)n*(long long)(n+1))/2;
        ans[0] = x;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends