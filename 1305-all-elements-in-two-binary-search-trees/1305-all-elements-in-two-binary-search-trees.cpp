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
    
    void solve(TreeNode* root1, vector<int>&ans) {
        if(root1) {
            solve(root1->left, ans);
            ans.push_back(root1->val);
            solve(root1->right, ans);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        solve(root1, a);
        solve(root2, b);
        vector<int> ans(a.size()+b.size());
        merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
        return ans;
    }
};