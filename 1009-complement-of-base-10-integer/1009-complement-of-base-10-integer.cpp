class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        bitset<32> b1(n);
        bool s = false;
        for(int i=31; i>=0; i--) {
            if(b1[i]==1) s = true;
            if(s) {
                if(b1[i]==1) b1[i]=0;
                else b1[i]=1;
            }
        }
        return b1.to_ullong();
    }
};