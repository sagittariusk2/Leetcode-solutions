class Solution {
public:
    int addDigits(int num) {
        int sum=num;
        while(sum>9) {
            int x=0;
            while(sum>0) {
                x += sum%10;
                sum /= 10;
            }
            sum=x;
        }
        return sum;
    }
};