class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 or k%5==0) return -1;
        int n=1, ans=1;
        for(int i=0; i<k; i++) {
            if(n%k==0) return ans;
            int x = n*10+1;
            n = x%k;
            ans++;
        }
        return -1;
    }
};