class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(int i: nums){
            ump[i]++;
        }
        priority_queue<pair<int, int>>pq;
        for(auto i: ump){
            pq.push({i.second,i.first});
        }
        vector<int> res;
        while(k--){
            auto [elem, count] = pq.top();
            res.push_back(count);
            pq.pop();
        }
        return res;
    }
};