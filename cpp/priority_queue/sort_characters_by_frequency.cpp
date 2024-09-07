//
// Created by Harsha Vardhan on 02/06/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct comparator {
    bool operator()(pair<char, int> &a, pair<char, int> &b) {
        return a.second < b.second;
    }
};

string frequencySort(string s) {
    unordered_map<char, int> umap;
    for (int i = 0; i < s.size(); i++) {
        umap[s[i]]++;
    }
    priority_queue<pair<char, int>, vector<pair<char, int>>, comparator> pq;
    for (auto it: umap) {
        pq.push({it.first, it.second});
    }
    string ans;
    while (!pq.empty()) {
        pair<char, int> t = pq.top();
        for (int i = 0; i < t.second; i++) {
            ans += t.first;
        }
        pq.pop();
    }
    return ans;
}

int main() {
    return 0;
}