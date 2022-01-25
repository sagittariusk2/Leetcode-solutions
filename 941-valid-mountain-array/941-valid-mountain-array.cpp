class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int x=-1;
        for(int i=1; i<arr.size(); i++) {
            if(arr[i]<arr[i-1]) {
                x=i;
                break;
            } else if(arr[i]==arr[i-1]) return false;
        }
        if(x==-1 or x==1) return false;
        for(; x<arr.size(); x++) {
            if(arr[x]>=arr[x-1]) {
                return false;
            }
        }
        return true;
    }
};