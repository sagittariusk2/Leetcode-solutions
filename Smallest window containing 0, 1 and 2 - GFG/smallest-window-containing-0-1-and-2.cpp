// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
  	bool check(string s)
  	{
  		if(s.find('0') == string::npos)
  			return false;

  		if(s.find('1') == string::npos)
  			return false;

  		if(s.find('2') == string::npos)
  			return false;

  		return true;
  	}

    int smallestSubstring(string s) 
    {
        // Code here
        if(!check(s))
        	return -1;

        int zero = -1;
        int one = -1;
        int two = -1;
        
        int mini = INT_MAX;
        for(int i = 0;i < s.size();i++)
        {
        	if(s[i] == '0')
        		zero = i;
        	if(s[i] == '1')
        		one = i;
        	if(s[i] == '2')
        		two = i;

        	if(zero != -1 and one != -1 and two != -1)
        	{
        		int min_ele = min({zero,one,two});
        		int max_ele = max({zero,one,two});
        		mini = min(mini,max_ele - min_ele + 1);
        	}
        }
        return mini;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends