class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0, x=0, f=0;
        for(auto i:flowerbed) {
            if(ans>=n) return true;
            if(i==0) {
                x++;
            } else {
                if(f==0) {
                    ans += (x/2);
                } else {
                    ans += ((x-1)/2);
                }
                f++;
                x=0;
            }
        }
        if(f==0) {
            ans += (x+1)/2;
        } else {
            ans += x/2;
        }
        if(n<=ans) return true;
        return false;
    }
};