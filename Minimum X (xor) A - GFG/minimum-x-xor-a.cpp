//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    int bin2dec(string str) {
        reverse(str.begin(), str.end());
        int ans = 0;
        for(int i=0; i<str.size(); i++) {
            if(str[i]=='0') {
                ans += pow(2, i);
            }
        }
        return ans;
    }
public:
    int minVal(int a, int b) {
        // code here
        string sa;
        int sb=0;
        while(b) {
            sb += (b%2);
            b/=2;
        }
        // cout << "sb : " << sb << endl;
        while(a) {
            int r=a%2;
            if(r) sa += '1';
            else sa += '0';
            a /= 2;
        }
        reverse(sa.begin(), sa.end());
        // cout << "sa : " << sa << endl;
        int i=0;
        string new_sa;
        while(i<sa.size()) {
            if(sb) {
                if(sa[i]=='1') {
                    sb--;
                }
                new_sa += '0';
            } else {
                new_sa += sa[i];
            }
            i++;
        }
        // cout << "new_sa : " << new_sa << endl;
        i = sa.size()-1;
        while(i>=0 and sb) {
            if(sa[i]=='0') {
                new_sa[i] = '1';
                sb--;
            }
            i--;
        }
        // cout << "new_sa : " << new_sa << endl;
        while(sb) {
            sb--;
            new_sa[i] += '1';
        }
        // cout << "new_sa : " << new_sa << endl;
        return bin2dec(sa)^bin2dec(new_sa);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends