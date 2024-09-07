//
// Created by Harsha Vardhan on 04/09/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int M = 1000000007;

int numberOfWaysHelper(int startPos, int endPos, int k, unordered_map<string, int> &umap) {
    if (k == 0) {
        if (startPos == endPos) {
            return 1;
        } else {
            return 0;
        }
    }
//    string l = to_string(startPos) + to_string(k);
//    if (umap.find(l) != umap.end()) return umap[l];
    return (numberOfWaysHelper(startPos + 1, endPos, k - 1, umap) % M +
                      numberOfWaysHelper(startPos - 1, endPos, k - 1, umap) % M);
}

int numberOfWays(int startPos, int endPos, int k) {
    unordered_map<string, int> umap;
    return numberOfWaysHelper(startPos, endPos, k, umap);
}

int main() {
    cout << numberOfWays(1, 1000, 999) << "\n";
    return 0;
}