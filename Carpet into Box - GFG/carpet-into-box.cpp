//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int carpetBox(int a, int b, int c, int d) {
        int ans = 0;
        if(a<b) swap(a, b);
        if(c<d) swap(c, d);
        while(a>c or b>d) {
            if(a<=c) {
                int b1 = b/2;
                a = max(a, b1);
                b = min(a, b1);
            } else {
                int a1 = a/2;
                a = max(a1, b);
                b = min(a1, b);
            }
            ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends