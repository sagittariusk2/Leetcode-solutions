// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> &arr) {
        // int i=n-2;
        // while(i>=0 && arr[i]>arr[i+1]) {
        //     i--;
        // }
        // int j=i+1;
        // if(i!=-1) {
        //     while(j<n && arr[j]>arr[i]) {
        //         j++;
        //     }
        //     j--;
        //     swap(arr[i], arr[j]);
        // }
        // sort(arr.begin()+i+1, arr.end());
        // return arr;
        
        int x=-1;
        
        for(int i=n-2; i>=0; i--) {
            if(arr[i]<arr[i+1]) {
                x=i;
                break;
            }
        }
        if(x!=-1) {
            int j=x+1;
            for(; j<n; j++) {
                if(arr[j]<arr[x]) {
                    break;
                }
            }
            j--;
            swap(arr[x], arr[j]);
        }
        x++;
        sort(arr.begin()+x, arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends