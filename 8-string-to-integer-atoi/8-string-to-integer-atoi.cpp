class Solution {
public:
    int myAtoi(string s) {
        int n = s.length(), i=0, ne=0, po=1, j=0;
        while(i<n and s[i]==' ') {
            i++;
        }
        if(i<n and s[i]=='-') {
            i++;
            ne=1;
            po=0;
        } else if(i<n and s[i]=='+') {
            i++;
            po=1;
            ne=0;
        }
        j=i;
        for(; i<n; i++) {
           if(s[i]<'0' or s[i]>'9' ) {
               break;
           } 
        }
        string x = s.substr(j, i-j);
        long ans=0;
        n = x.length();
        for(int i=0; i<n; i++) {
            ans = (ans*10)+(x[i]-48);
            if(ne and (0-ans)<=INT_MIN) return INT_MIN;
            else if(po and ans>=INT_MAX) return INT_MAX;
        }
        if(ne) return 0-ans;
        return ans;
    }
};