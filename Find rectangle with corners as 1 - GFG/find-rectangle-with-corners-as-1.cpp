// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& m)
    {
        int n = m.size();
        int n1 = m[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n1;j++){
                if(m[i][j] == 1){
                    
                    int r=i,c=j;
                    
                    for(int stx=1;r+stx<n;stx++){
                        for(int sty = 1;c+sty<n1;sty++){

                            int one = 0, two = 0, three = 0;
                            
                            one = m[r][c+sty];
                            two = m[r+stx][c+sty];
                            three = m[r+stx][c];

                            if(one && two && three){
                                return true;
                            }

                        }
                    }
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 


  // } Driver Code Ends