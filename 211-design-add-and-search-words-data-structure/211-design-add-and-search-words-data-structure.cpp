class WordDictionary {
private:
    struct Node {
        bool val;
        vector<Node*> next;
        Node() {
            val = false;
            next = vector<Node*>(26, nullptr);
        }
    };
    Node *root;

    bool solve(Node* temp, string &word, int i) {
        if(temp) {
            if (i == word.length()) {
                if(temp->val) return true;
                else return false;
            }
            if (word[i] == '.') {
                bool x = false;
                for (int j = 0; j < 26; j++) {
                    if(temp->next[j])
                    x = x or solve(temp->next[j], word, i+1);
                }
                return x;
            }
            if (temp->next[word[i] - 'a']) {
                return solve(temp->next[word[i] - 'a'], word, i+1);
            }
        }
        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node *temp=root;
        for(int i=0; i<word.length(); i++) {
            if(temp->next[word[i]-'a']) {
                temp = temp->next[word[i]-'a'];
            } else {
                Node *t=new Node();
                temp->next[word[i]-'a']=t;
                temp = t;
            }
            if(i==word.length()-1) temp->val = true;
        }
    }

    bool search(string word) {
        Node *temp = root;
        return solve(temp, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */