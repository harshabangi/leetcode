//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct comparator {
    bool operator()(const pair<int, string> a, const pair<int, string> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

vector<string> topKFrequent(vector<string> &words, int k) {
    vector<string> ans;
    unordered_map<string, int> umap;
    for (int i = 0; i < words.size(); i++) {
        umap[words[i]]++;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
    for (auto it: umap) {
        pq.push({it.second, it.first});
    }
    while (k--) {
        pair<int, string> t = pq.top();
        pq.pop();
        ans.push_back(t.second);
    }
    return ans;
}

int main() {
    vector<string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    topKFrequent(words, k);
    return 0;
}
