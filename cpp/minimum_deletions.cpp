//
// Created by Harsha Vardhan on 08/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

int minDeletions(string s) {
    unordered_map<char, int> umap;
    for (int i = 0; i < s.size(); i++) {
        umap[s[i]]++;
    }
    unordered_map<int, int> umap2;
    unordered_set<int> uset;
    for (auto it: umap) {
        umap2[it.second]++;
        uset.insert(it.second);
    }
    int ans = 0;
    for (auto k: umap2) {
        for (int j = k.second; j > 1; j--) {
            bool flag = false;
            for (int i = k.first; i >= 1; i--) {
                if (uset.find(i) == uset.end()) {
                    uset.insert(i);
                    flag = true;
                    ans += k.first - i;
                    break;
                }
            }
            if (!flag) ans += k.first;
        }
    }
    return ans;
}

int main() {
    cout << minDeletions("abcabc") << "\n";
    return 0;
}
