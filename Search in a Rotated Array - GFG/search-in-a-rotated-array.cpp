// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int search(int A[], int l, int h, int key) {
        int s = l, e = h;
        int small_index;
        while(s<=e) {
            int mid = (s+e)/2;
            if(A[mid]>=A[e]) {
                s = mid+1;
            } else {
                small_index = mid;
                e = mid-1;
            }
        }
        
        int ans = -1;
        s = 0, e = small_index-1;
        while(s<=e) {
            int mid = (s+e)/2;
            if(A[mid]>key) {
                e = mid-1;
            } else if(A[mid]<key) {
                s = mid +1;
            } else {
                ans = mid;
                break;
            }
        }
        
        s = small_index, e = h;
        while(s<=e) {
            int mid = (s+e)/2;
            if(A[mid]>key) {
                e = mid-1;
            } else if(A[mid]<key) {
                s = mid +1;
            } else {
                ans = mid;
                break;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends