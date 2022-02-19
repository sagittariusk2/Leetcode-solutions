// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    string calc_Sum(int *a,int n,int *b,int m) {
        // starting from the end positions of the two array
        string ans;
        n--, m--;
        int c = 0;
        
        // add two elements with carry till any of the pointer finishes
        while(n>=0 and m>=0) {
            int x = a[n]+b[m]+c;
            c = x/10;
            ans += to_string(x%10);
            n--;
            m--;
        }
        
        // add the remaining integers with 0 and append in the answer
        while(n>=0) {
            int x = a[n]+c;
            c = x/10;
            ans += to_string(x%10);
            n--;
        }
        
        while(m>=0) {
            int x = b[m]+c;
            c = x/10;
            ans += to_string(x%10);
            m--;
        }
        
        while(c!=0) {
            ans += to_string(c%10);
            c /= 10;
        }
        
        reverse(ans.begin(), ans.end());
        
        int zero=0;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i]!='0') {
                zero=i;
                break;
            }
        }
        
        return ans.substr(zero);
    }
};

// { Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}  // } Driver Code Ends