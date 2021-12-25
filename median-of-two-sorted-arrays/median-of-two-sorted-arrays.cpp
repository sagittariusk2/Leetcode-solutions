class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n<m) {
            return findMedianSortedArrays(nums2, nums1);
        } else {
            int i=0, j=m, len=m+n;
            while(i<=j) {
                int mid = (i+j)/2;
                int y =((len+1)/2)-mid;

                int a1 = (y==0)?INT_MIN:nums1[y-1];
                int a2 = (y==n)?INT_MAX:nums1[y];
                int b1 = (mid==0)?INT_MIN:nums2[mid-1];
                int b2 = (mid==m)?INT_MAX:nums2[mid];

                if(a1<=b2 and a2>=b1) {
                    if(len%2==1) return (double)max(a1, b1);
                    else return ((double)max(a1, b1)+(double)min(a2, b2))/2.0;
                } else if(a2<b1) j = mid-1;
                else i = mid+1;
            }
        }
        return 0;
    }
};