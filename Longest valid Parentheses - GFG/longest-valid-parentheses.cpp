// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        // take a stack
        stack<int> st;
        st.push(-1);
        int ans=0;
        
        // iterate through the string
        for(int i=0; i<S.length(); i++) {
            // if current element is '(' the push with index
            if(S[i]=='(') {
                st.push(i);
            }
            // else
            else {
                // if stack is not empty then calulate the answer from top from stack pop from stack
                st.pop();
                if(st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i-st.top());
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends