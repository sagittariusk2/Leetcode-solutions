// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution {
public:
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n) {
        vector<int> a;
        for(int i=0; i<n; i++) {
            a.push_back(p[i].petrol-p[i].distance);
        }
        for(int i=0; i<n-1; i++) {
            a.push_back(a[i]);
        }
        int na = a.size();
        int i=-1, j=0, x=0;
        while(j<na) {
            if(x<0) {
                i++;
                x-=a[i];
            } else {
                if(j-i-1==n) return i+1;
                x+=a[j];
                j++;
            }
        }
        if(j-i-1==n) return i+1;
        return -1;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends