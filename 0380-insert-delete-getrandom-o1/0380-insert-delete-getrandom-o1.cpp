class RandomizedSet {
    std::unordered_map<int, int> valToIndex;
    std::vector<int> values;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.count(val)) return false;
        valToIndex[val] = values.size();
        values.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) return false;
        int idx = valToIndex[val];
        int last = values.back();
        values[idx] = last;
        valToIndex[last] = idx;
        values.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        return values[rand() % values.size()];
    }
};