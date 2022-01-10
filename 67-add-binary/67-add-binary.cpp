class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int j=b.length(), i=a.length(), c=0;
        while(j!=0 or i!=0) {
            if(i==0) {
                if(c==0 and b[j-1]=='0') ans += '0';
                else if(c==0 and b[j-1]=='1') ans += '1';
                else if(c==1 and b[j-1]=='0') {
                    ans += '1';
                    c = 0;
                } else {
                    ans += '0';
                    
                }
            } else if(j==0) {
                if(c==0 and a[i-1]=='0') ans += '0';
                else if(c==0 and a[i-1]=='1') ans += '1';
                else if(c==1 and a[i-1]=='0') {
                    ans += '1';
                    c = 0;
                } else {
                    ans += '0';
                }
            } else {
                if(c==0) {
                    if(a[i-1]=='0' and b[j-1]=='0') ans += '0';
                    else if(a[i-1]=='0' and b[j-1]=='1') ans += '1';
                    else if(a[i-1]=='1' and b[j-1]=='0') ans += '1';
                    else {
                        ans += '0';
                        c = 1;
                    }
                } else {
                    if(a[i-1]=='0' and b[j-1]=='0') {
                        ans += '1';
                        c = 0;
                    }
                    else if(a[i-1]=='0' and b[j-1]=='1') ans += '0';
                    else if(a[i-1]=='1' and b[j-1]=='0') ans += '0';
                    else ans += '1';
                }
            }
            i=max(0, i-1);
            j=max(0, j-1);
        }
        if(c==1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};