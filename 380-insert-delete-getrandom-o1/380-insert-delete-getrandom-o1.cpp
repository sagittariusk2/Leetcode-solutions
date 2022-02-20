class RandomizedSet {
private:
    unordered_map<int, int> mpp; // val, index in vector
    vector<int> v1;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(mpp.find(val)==mpp.end()) {
            mpp[val]= v1.size();
            v1.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mpp.find(val)==mpp.end()) return false;
        int index = mpp[val];
        mpp[v1[v1.size()-1]]=index;
        mpp.erase(val);
        swap(v1[v1.size()-1], v1[index]);
        v1.pop_back();
        return true;
    }
    
    int getRandom() {
        int x = rand();
        return v1[x%v1.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */