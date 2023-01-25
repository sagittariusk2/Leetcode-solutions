//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string caps, small;
        vector<bool> pos(n, false);
        for(int i=0; i<n; i++) {
            if(str[i]<='z' and str[i]>='a') {
                small += str[i];
            } else {
                caps += str[i];
                pos[i] = true;
            }
        }
        
        sort(caps.begin(), caps.end());
        sort(small.begin(), small.end());
        
        string ans;
        int i=0, j=0;
        for(auto it:pos) {
            if(it) {
                ans+= caps[i++];
            } else {
                ans += small[j++];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends