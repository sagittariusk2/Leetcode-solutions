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
    int ans = 0;
    void solve(TreeNode* root, int mx, int mn) {
        if(root) {
            int x = max(mx, root->val);
            int y = min(mn, root->val);
            ans = max(ans, abs(x-y));
            solve(root->left, x, y);
            solve(root->right, x, y);
        }
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root)
        solve(root, INT_MIN, INT_MAX);
        return ans;
    }
};