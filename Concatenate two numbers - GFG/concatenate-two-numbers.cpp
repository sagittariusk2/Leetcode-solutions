// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int N, int X, vector<int> numbers){
        // code here
        multiset<string> v1;
        for(auto i:numbers) {
            v1.insert(to_string(i));
        }
        string s = to_string(X);
        string a = "";
        a += s[0];
        string b = s.substr(1);
        long long ans = 0;
        
        for(int i=1; i<s.length(); i++) {
            long long x = v1.count(a);
            long long y = v1.count(b);
            ans += (x*y);
            if(a==b) {
                ans -= x;
            }
            a += s[i];
            reverse(b.begin(), b.end());
            b.resize(b.size()-1);
            reverse(b.begin(), b.end());
        }
        
        return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends