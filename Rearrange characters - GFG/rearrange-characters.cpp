// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution {
public:
    string rearrangeString(string str) {
        // store the char and frequencies in a map
        vector<int> mpp(26, 0);
        for(auto i:str) {
            mpp[i-'a']++;
        }
        int n = str.size();
        for(int i=0; i<26; i++) {
            if((n+1)/2<mpp[i]) {
                return "-1";
            }
        }
        // else possible
        int i=0, j=1;
        for(int k=0; k<26; k++) {
            while(mpp[k]--) {
                if(i<n) {
                    str[i] = k+'a';
                    i += 2;
                } else {
                    str[j] = k+'a';
                    j += 2;
                }
            }
        }
        
        return str;
            // put each char in alternate fashion
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends