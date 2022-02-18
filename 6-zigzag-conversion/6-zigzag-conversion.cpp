class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int n=s.length();
        for(int i=0; i<numRows; i++) {
            int a = max(0, i*2-1); // skips for the first time
            int b = max(0, (numRows-i-1)*2-1); // skips for the second time
            
            // cout << a << " " << b << endl;
            
            int start = i;
            while(start<n) {
                ans += s[start];
                if(a!=0 and b!=0 and start+b+1<n) ans += s[start+b+1];
                if(a==0 or b==0) start += (a+b+1);
                else start += (a+b+2);
            }
        }
        return ans;
    }
};