// { Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int minLength(string s, int n) {
        // code here
        stack<char> st;
        for(auto i:s) {
            if(st.empty()) {
                st.push(i);
            } else {
                char x = st.top();
                string x1 = "";
                x1+=x;
                x1+=i;
                if(x1=="12" or x1=="21" or x1=="34" or x1=="43" or x1=="56" or x1=="65" or x1=="78" or x1=="87" or x1=="90" or x1=="09") {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        return st.size();
    } 
};


// { Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends