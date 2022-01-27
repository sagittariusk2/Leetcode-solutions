class TRIofBinaryDigits {
private:
    struct Node{
        int count;
        Node *left, *right;
        Node() {
            count = 0;
            left = right = nullptr;
        }
    };
    Node *root;
public:
    TRIofBinaryDigits() {
        root = new Node();
    }

    void insert(int n) {
        bitset<64> b1(n);
        Node *temp=root;
        for(int i=63; i>=0; i--) {
            if(b1[i]) {
                if(temp->right) {
                    temp = temp->right;
                } else {
                    Node *t=new Node();
                    temp->right=t;
                    temp = temp->right;
                }
            } else {
                if(temp->left) {
                    temp = temp->left;
                } else {
                    Node *t=new Node();
                    temp->left=t;
                    temp = temp->left;
                }
            }
        }
    }

    int XORSearch(int n) {
        bitset<64> b1(n);
        b1.flip();
        Node *temp = root;
        string x="";
        for(int i=63; i>=0; i--) {
            if(b1[i]) {
                if(temp->right) {
                    temp = temp->right;
                    x += '1';
                } else if(temp->left) {
                    temp = temp->left;
                    x += '0';
                }
            } else {
                if(temp->left) {
                    temp = temp->left;
                    x += '0';
                } else if(temp->right) {
                    temp = temp->right;
                    x += '1';
                }
            }
        }
        if(x=="") return -1;
        bitset<64> b2(x);
        return b2.to_ullong();
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TRIofBinaryDigits tri;
        tri.insert(nums[0]);
        int ans=0;
        for(int i=1; i<nums.size(); i++) {
            int y = tri.XORSearch(nums[i]);
            ans = max(ans, y^nums[i]);
            tri.insert(nums[i]);
        }
        return ans;
        
    }
};