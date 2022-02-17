/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    int solve(TreeNode* root, int &ans) {
        if(root==nullptr) return -1;
        
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        
        if(l==0 or r==0) {
            ans++;
            return 1;
        }
        
        if(l==1 or r==1) {
            return -1;
        }
        
        return 0;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(solve(root, ans)==0) ans++;
        return ans;
    }
};