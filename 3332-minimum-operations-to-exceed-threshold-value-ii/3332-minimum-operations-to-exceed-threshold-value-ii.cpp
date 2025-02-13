class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long int, vector<long long int>,greater<long long int>> pq;
        for(auto it:nums){
            pq.push(it);
        }
        int count=0;
        while(pq.top()<k){
            long long int val = pq.top();
            pq.pop();
            pq.push(2*val+pq.top());
            pq.pop();
            count++;
        }
        return count;
    }
};