#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>  // for rand()
#include <ctime>    // for seeding rand()

class RandomizedCollection {
private:
    std::vector<int> arr; // Store elements
    std::unordered_map<int, std::unordered_set<int>> freqIndex; // val -> set of indices

public:
    RandomizedCollection() {
        std::srand(std::time(nullptr)); // Seed random number generator
    }

    bool insert(int val) {
        arr.push_back(val);
        freqIndex[val].insert(arr.size() - 1);
        return freqIndex[val].size() == 1; // true if first occurrence
    }

    bool remove(int val) {
        // If val not present, cannot remove
        if (freqIndex.find(val) == freqIndex.end() || freqIndex[val].empty())
            return false;

        // Get an arbitrary index of val and remove it from freqIndex
        int curr = *(freqIndex[val].begin());
        freqIndex[val].erase(curr);

        int lastIndex = arr.size() - 1;

        if (curr == lastIndex) {
            // Removing last element
            arr.pop_back();
            return true;
        }

        // Swap last element with element at curr
        int lastVal = arr[lastIndex];
        arr[curr] = lastVal;

        // Update freqIndex for lastVal
        freqIndex[lastVal].erase(lastIndex);
        freqIndex[lastVal].insert(curr);

        arr.pop_back();
        return true;
    }

    int getRandom() {
        int randomIndex = std::rand() % arr.size();
        return arr[randomIndex];
    }
};


/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */