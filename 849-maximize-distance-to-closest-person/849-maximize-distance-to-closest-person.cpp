class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> l(n, INT_MAX), r(n, INT_MAX);
        int x = -1;
        for(int i=0; i<n; i++) {
            if(seats[i]==1) x=i;
            if(x!=-1) l[i] = i-x;
        }
        x=-1;
        for(int i=n-1; i>=0; i--) {
            if(seats[i]==1) x=i;
            if(x!=-1) r[i] = x-i;
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, min(l[i], r[i]));
        }
        return ans;
    }
};