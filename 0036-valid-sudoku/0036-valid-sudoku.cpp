class Solution {
public:
    
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            map<char, int> mpp1, mpp2;
            for(int j=0; j<9; j++) {
                mpp1[board[i][j]]++;
                mpp2[board[j][i]]++;
            }
            for(auto j:mpp1) {
                if(j.first!='.' && j.second>1)
                    return false;
            }
            for(auto j:mpp2) {
                if(j.first!='.' && j.second>1)
                    return false;
            }
        }
        
        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {
                map<char, int> mpp;
                for(int k=0; k<3; k++) {
                    for(int l=0; l<3; l++) {
                        mpp[board[i+k][j+l]]++;
                    }
                }
                for(auto j:mpp) {
                    if(j.first!='.' && j.second>1)
                        return false;
                }
            }
        }
        
        return true;
    }
};