class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> freqMap;
    priority_queue<pair<long long, int>> maxHeap; // {frequency, id}
    int n = nums.size();
    vector<long long> ans(n);

    for (int i = 0; i < n; ++i) {
        int id = nums[i];
        int change = freq[i];

        freqMap[id] += change;

        if (freqMap[id] == 0) {
            freqMap.erase(id);  // Remove ID entirely if count is 0
        }

        if (freqMap.count(id)) {
            maxHeap.push({freqMap[id], id});
        }

        // Clean the top of the heap
        while (!maxHeap.empty()) {
            auto [f, x] = maxHeap.top();
            if (freqMap.count(x) && freqMap[x] == f) {
                break; // Valid top
                // it is a good apporach kyunki hame bss top check kerna hai ki is it good or not if not that is we updated the same element somewhere now or previously and uss se koi aur problem na aai to remove it.
            }
            maxHeap.pop(); // Stale entry
        }

        if (maxHeap.empty()) ans[i] = 0;
        else ans[i] = maxHeap.top().first;
    }

    return ans;

        
    }
};