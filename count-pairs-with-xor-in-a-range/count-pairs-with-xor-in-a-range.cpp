class Solution {
private:
    struct Node {
        int val;
        Node *left;
        Node *right;

        Node() {
            val = 0;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* create(int h) {
        if(h<16) {
            Node* temp = new Node();
            temp->left = create(h+1);
            temp->right = create(h+1);
            return temp;
        }
        return nullptr;
    }

    Node *root;
    
    void start() {
        root = create(0);
    }
    
    void insert(int x) {
        bitset<15> b1(x);
        Node* temp = root;
        if(temp)
        temp->val++;
        for(int i=14; i>=0; i--) {
            if(temp) {
            if(b1[i]==0) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
            temp->val++;
            }
        }
    }

    int count(int x, int y) {
        bitset<15> b1(x), b2(y);
        int ans=0;
        Node *temp = root;
        for(int i=14; i>=0; i--) {
            if(temp) {
                if(b1[i]==1) {
                    if(b2[i]==0) {
                        temp = temp->right;
                    } else {
                        ans += temp->right->val;
                        temp = temp->left;
                    }
                } else {
                    if(b2[i]==0) {
                        temp = temp->left;
                    } else {
                        ans += temp->left->val;
                        temp = temp->right;
                    }
                }
            }
        }
        if(temp)
            ans += temp->val;
        return ans;
    }
public:
    int countPairs(vector<int>& nums, int low, int high) {
        start();
        int ans=0;
        for(auto i:nums) {
            ans += count(i, high);
            ans -= count(i, low-1);
            insert(i);
        }
        return ans;
    }
};