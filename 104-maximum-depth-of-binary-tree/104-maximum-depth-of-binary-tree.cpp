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
public:
    int ans=0;
    
    void solve(TreeNode* root, int l) {
        if(root) {
            ans=max(ans, l+1);
            solve(root->left, l+1);
            solve(root->right, l+1);
        }
    }
    
    int maxDepth(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};