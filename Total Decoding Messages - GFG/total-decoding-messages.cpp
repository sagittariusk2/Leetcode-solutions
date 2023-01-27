//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int CountWays(string str) {
	    int M = 1000000007;
	    int n= str.size();
	    int a=1, b=1, c;
	    for(int i=0; i<n; i++) {
	        int x=0, y=0;
	        if(i-1>=0) {
	            if(str[i-1]=='1') {
	                y=1;
	            } else if(str[i-1]=='2') {
	                if(str[i]>='0' and str[i]<='6') {
	                    y=1;
	                }
	            }
	        }
	        if(str[i]!='0') {
	            x=1;
	        }
	        c = ((a*y)%M+(b*x)%M)%M;
	        a=b;
	        b=c;
	    }
	    return c;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends