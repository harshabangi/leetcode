//
// Created by Harsha Vardhan on 24/10/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int dfs(string s, unordered_map<string, int> &umap) {
    if (s.empty()) return 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        string x = s.substr(0, i + 1);
        if (umap.find(x) != umap.end()) {
            ans = 1 + dfs(s.substr(i + 1), umap);
        }
    }
    return ans;
}

vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    unordered_map<string, int> umap;
    for (int i = 0; i < words.size(); i++) {
        umap[words[i]]++;
    }

    vector<string> ans;

    for (int i = 0; i < words.size(); i++) {
        if (dfs(words[i], umap) >= 2) {
            ans.push_back(words[i]);
        }
    }
    return ans;
}


int main() {
    return 0;
}
