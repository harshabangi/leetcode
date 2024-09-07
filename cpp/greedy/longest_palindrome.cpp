//
// Created by Harsha Vardhan on 27/06/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s) {
    unordered_map<int, int> umap;
    for (int i = 0; i < s.size(); i++) {
        umap[s[i]]++;
    }
    int c = 0;
    int maxOdd = 0;
    char t;
    for (auto it: umap) {
        if (it.second % 2 == 0) {
            c += it.second;
        } else {
            if (it.second > maxOdd) {
                t = it.first;
                maxOdd = it.second;
            }
        }
    }
    c += maxOdd;
    for (auto it: umap) {
        if (it.second % 2 != 0 && it.first != t) {
            c += it.second - 1;
        }
    }
    return c;
}

int main() {
    cout << longestPalindrome("abccccdd") << "\n";
    return 0;
}
