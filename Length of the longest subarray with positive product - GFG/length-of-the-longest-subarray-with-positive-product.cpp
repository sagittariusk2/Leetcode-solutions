//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
        // Function to return the length of the
        //longest subarray with ppositive product
    int maxLength(vector<int> &arr,int n){
       int negative = -1;
       int negativeCount = 0;
       int count =0;
       int start = 0;
       for(int i=0 ; i<n ; i++) {
           if(arr[i] == 0 ) {
              start = i+1;
              negativeCount = 0;
              negative = -1;
              continue;
            }
            if(arr[i]<0) {
                negativeCount++; 
                if(negative==-1)
                    negative=i;
            }
            if(negativeCount%2==0){
                count = max(count,i-start+1);
            } else {
                count = max(count,i-negative);
            }
       }
       return count ;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends