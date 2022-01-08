// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<string> AllPossibleStrings(string s) {
	    int n=s.length();
	    vector<string> v1;
	    for(int i=1; i<65536; i++) {
	        bitset<16> b1(i);
	        string ans;
	        for(int i=0; i<n; i++) {
	            if(b1[i]) {
	                ans += s[i];
	            }
	        }
	        v1.push_back(ans);
	        if(ans.length()==n) break;
	    }
	    sort(v1.begin(), v1.end());
	    return v1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends