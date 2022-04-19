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
    TreeNode *curr=nullptr, *next=nullptr, *first=nullptr;
    
    void solve(TreeNode* root) {
        if(root) {
            solve(root->left);
            if(!first) {
                curr = next;
                next = root;
                if(curr) {
                    if(curr->val>next->val) {
                        first = curr;
                        curr = next;
                    }
                }
            } else {
                next = root;
                if(next->val<curr->val) {
                    curr = next;
                }
            }
            solve(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(curr->val, first->val);
    }
};