/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node* > q1;
        if(root) q1.push(root);
        while(!q1.empty()) {
            int n = q1.size();
            Node* p = q1.front(), *q=q1.front();
            q1.pop();
            if(n==1) {
                p->next=nullptr;
                if(p->left) q1.push(p->left);
                if(p->right) q1.push(p->right);
            } else {
                p=q1.front();
                q1.pop();
                n-=2;
                while(n--) {
                    q->next=p;
                    if(q->left) q1.push(q->left);
                    if(q->right) q1.push(q->right);
                    q=p;
                    
                    p=q1.front();
                    q1.pop();
                }
                q->next=p;
                if(q->left) q1.push(q->left);
                if(q->right) q1.push(q->right);
                if(p->left) q1.push(p->left);
                if(p->right) q1.push(p->right);
            }
        }
        return root;
    }
};