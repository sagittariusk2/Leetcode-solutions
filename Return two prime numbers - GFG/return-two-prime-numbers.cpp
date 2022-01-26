// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int> primeList(int N) {
        vector<int> prime;
        vector<bool> p(N+1, true);
        p[0]=p[1]=false;
        if(N<2) return prime;
        for(int i=2; i<N; i++) {
            if(p[i]) {
                prime.push_back(i);
                for(int j=i*i; j<=N; j+=i) {
                    p[j]=false;
                }
            }
        }
        return prime;
    }

    vector<int> primeDivision(int N){
        // code here
        vector<int> prime=primeList(N+1);
        int i=0, j=prime.size()-1;
        while(i<=j) {
            if(prime[i]+prime[j]<N) {
                i++;
            } else if(prime[i]+prime[j]>N) {
                j--;
            } else {
                return vector<int>({prime[i], prime[j]});
            }
        }
        return vector<int>({0, 0});
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends