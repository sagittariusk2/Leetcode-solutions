//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

bool cmp(string str1, string str2) {
    if(str1.size()==str2.size()) {
        return str1>str2;
    }
    return str1.size()<str2.size();
}

class Solution {
public:
    string longestString(vector<string> &words) {
        sort(words.begin(), words.end());
        vector<string> ans;
        for(auto i:words) {
            string str;
            bool s = true;
            for(auto j:i) {
                str += j;
                if(!binary_search(words.begin(), words.end(), str)) {
                    s = false;
                }
            }
            if(s) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        if(ans.size()==0) return "";
        return ans[ans.size()-1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends