// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> &arr) {
        // find the index of first element where it has decreased from last
        int i=n-2;
        while(i>=0 and arr[i]>=arr[i+1]) {
            i--;
        }
        
        if(i!=-1) {
            // find the index which is just greater then the last found index
            int j=i;
            while(j+1<n and arr[j+1]>arr[i]) {
                j++;
            }
            swap(arr[j], arr[i]);
            // swap these two
        }
        sort(arr.begin()+i+1, arr.end());
        // sort remaining
        
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