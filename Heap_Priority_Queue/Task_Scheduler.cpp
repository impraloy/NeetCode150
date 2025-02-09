class Solution {
private:
    struct Comparator {
        bool operator() (pair<char, int> &a, pair<char, int> &b) {
            return a.second < b.second; // Custom comparison logic for a max-heap
        }
    };

public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count Task Frequencies
        unordered_map<char, int> freq;
        for (auto &task : tasks) { 
            freq[task]++; 
        }

        // Step 2: Initialize Max-Heap with Custom Comparator
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comparator> maxHeap;
        for (auto &kv : freq) {
            maxHeap.push({ kv.first, kv.second });
        }

        // Step 3: Initialize Waiting Queue
        queue<tuple<char, int, int>> q;
        
        int intervals = 0;

        // Step 4: Simulation Loop
        while (!maxHeap.empty() || !q.empty()) {
            // Handle Cooldown and Reinsertion into Max-Heap
            if (!q.empty()) {
                auto [task, remaining, interval] = q.front();
                if (interval == intervals) {
                    maxHeap.push({ task, remaining });
                    q.pop();
                }
            }

            // Process Next Task
            if (maxHeap.empty()) { 
                intervals++; 
                continue; 
            }

            auto [task, remaining] = maxHeap.top();
            maxHeap.pop();
            remaining--;

            // Check if Task Needs to be Reinserted into Waiting Queue
            if (remaining > 0 && n > 0) {
                q.push(make_tuple(task, remaining, intervals + n + 1));
            } else if (remaining > 0) {
                maxHeap.push({ task, remaining });
            }

            intervals++;
        }

        return intervals;
    }
};