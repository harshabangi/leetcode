//
// Created by Harsha Vardhan on 10/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> umap;
    unordered_set<int> nodesWithZeroIncomingEdges;

    for (int &num : nums) {
        umap[num] = INT_MAX;
    }
    for (int &num : nums) {
        if (umap.find(num - 1) == umap.end()) {
            nodesWithZeroIncomingEdges.insert(num);
        }
        if (umap.find(num + 1) != umap.end()) {
            umap[num] = num + 1;
        }
    }
    int longestStreak = 0;
    for (int k: nodesWithZeroIncomingEdges) {
        int streak = 0;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            streak++;
            if (umap[t] != INT_MAX) {
                q.push(umap[t]);
            }
        }
        longestStreak = max(longestStreak, streak);
    }
    return longestStreak;
}

int recur(unordered_map<int, int> &umap, int k) {
    if (umap[k] == INT_MAX) {
        return 1;
    }
    return 1 + recur(umap, umap[k]);
}

int longestConsecutive2(vector<int> &nums) {
    unordered_map<int, int> umap;
    unordered_set<int> nodesWithZeroIncomingEdges;

    for (int &num : nums) {
        umap[num] = INT_MAX;
    }
    for (int &num : nums) {
        if (umap.find(num - 1) == umap.end()) {
            nodesWithZeroIncomingEdges.insert(num);
        }
        if (umap.find(num + 1) != umap.end()) {
            umap[num] = num + 1;
        }
    }
    int longestStreak = 0;
    for (int k: nodesWithZeroIncomingEdges) {
        longestStreak = max(longestStreak, recur(umap, k));
    }
    return longestStreak;
}

int main() {
    vector<int> nums{100, 4, 200, 1, 3, 2};
    cout << longestConsecutive2(nums) << "\n";
    return 0;
}
