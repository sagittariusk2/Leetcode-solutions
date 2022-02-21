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
class BSTIterator {
private:
    queue<TreeNode*> it_queue;
    
    void fill_queue(TreeNode* root) {
        if(root) {
            fill_queue(root->left);
            it_queue.push(root);
            fill_queue(root->right);
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        fill_queue(root);
    }
    
    int next() {
        int ans = it_queue.front()->val;
        it_queue.pop();
        return ans;
    }
    
    bool hasNext() {
        return !it_queue.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */