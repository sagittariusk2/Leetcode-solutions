class Solution {
public:
    int findComplement(int num) {
        bitset<32> b1(num);
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