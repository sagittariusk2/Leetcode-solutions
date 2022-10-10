class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        for(int i=0; i<n; i++) {
            if(palindrome[i]!='a') {
                if(i!=n/2 or n%2==0) {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};