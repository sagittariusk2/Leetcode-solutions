class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long i=1, j=*max_element(piles.begin(), piles.end());
        while(i<j) {
            long long mid = (i+j)/2;
            int x = 0;
            for(auto i:piles) {
                x += i/mid + (i%mid!=0);
            }
            if(x<=h) {
                j = mid;
            } else{
                i = mid+1;
            }
        }
        return j;
    }
};