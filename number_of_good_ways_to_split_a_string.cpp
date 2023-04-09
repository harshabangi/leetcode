//
// Created by Harsha Vardhan on 04/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSplits(string s) {
    unordered_map<char, int> umap1;
    unordered_map<char, int> umap2;

    for (int i = 0; i < s.size(); i++) {
        umap2[s[i]]++;
    }

    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        umap1[s[i]]++;
        umap2[s[i]]--;
        if (umap2[s[i]] == 0) umap2.erase(s[i]);
        if (umap1.size() == umap2.size()) ans++;
    }
    return ans;
}

int main() {
    return 0;
}
