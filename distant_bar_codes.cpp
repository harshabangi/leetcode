//
// Created by Harsha Vardhan on 30/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


struct comparator {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};


vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    unordered_map<int, int> umap;
    int n = barcodes.size();
    for (int i = 0; i < n; i++) {
        umap[barcodes[i]]++;
    }
    vector<pair<int, int>> t;
    for (auto it: umap) {
        t.emplace_back(it.first, it.second);
    }
    sort(t.begin(), t.end(), comparator());
    vector<int> ans(n, 0);
    int c = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t[i].second; j++) {
            if (c >= n) {
                c = 1;
            }
            ans[c] = t[i].first;
            c += 2;
        }
    }
    return ans;
}

int main() {
    vector<int> barcodes{1, 2, 1, 2, 3, 3, 3};
    rearrangeBarcodes(barcodes);
    return 0;
}
