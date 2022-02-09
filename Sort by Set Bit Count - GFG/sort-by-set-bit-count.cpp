// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n) {
        vector<vector<int>> v1(21);
        for(int i=0; i<n; i++) {
            bitset<21> b1(arr[i]);
            v1[b1.count()].push_back(arr[i]);
        }
        int i=0;
        for(int j=20; j>=0; j--) {
            for(auto k:v1[j]) {
                arr[i++] = k;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends