// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> move = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
	pair<int, int> endpointofmatrix(int x, int y, int dir, vector<vector<int>> &matrix, int row, int col) {
		if (matrix[x][y]) { //if startpoint is 1
			matrix[x][y] = 0; //set point=0
			dir = (dir + 1) % 4; //update direction
		}
		int newx = x + move[dir][0];
		int newy = y + move[dir][1];
		if (newx < 0 || newy < 0 || newx >= row || newy >= col) {
			return {x, y};
		}
		return endpointofmatrix(newx, newy, dir, matrix, row, col);
	}
	pair<int, int> endPoints(vector<vector<int>> matrix) {
		int x = 0;
		int y = 0;
		int dir = 0;
		int row = matrix.size();
		int col = matrix[0].size();
		return endpointofmatrix(x, y, dir, matrix, row, col);
	}
};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends