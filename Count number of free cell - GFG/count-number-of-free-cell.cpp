//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
public:
    vector<long long int> countZero(int n, int k, vector<vector<int>>& arr) {
        vector<bool> hr(n, false), vr(n, false);
        long long int cn_hr=0, cn_vr=0;
        long long int curr = n*n;
        vector<long long int> ans;
        for(auto i:arr) {
            i[0]--;
            i[1]--;
            int x=0, y=0;
            if(!hr[i[0]]) {
                x=n-cn_vr;
                hr[i[0]]=true;
                cn_hr++;
            }
            if(!vr[i[1]]) {
                y=n-cn_hr;
                vr[i[1]]=true;
                cn_vr++;
            }
            curr -= (x+y);
            ans.push_back(curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends