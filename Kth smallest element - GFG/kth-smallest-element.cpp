// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        srand(time(0));
        int pivot=l+rand()%(r-l+1);
        swap(arr[pivot], arr[l]);
        int i=l+1, j=r;
        while(i<=j) {
            if(arr[i]<arr[l]) i++;
            else if(arr[j]>arr[l]) j--;
            else {
                swap(arr[i++], arr[j--]);
            }
        }
        swap(arr[l], arr[j]);
        if(j==k-1) return arr[j];
        else if(j>k-1) return kthSmallest(arr, l, j-1, k);
        else return kthSmallest(arr, j+1, r, k);
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends