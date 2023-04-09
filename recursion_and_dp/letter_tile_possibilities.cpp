//
// Created by Harsha Vardhan on 09/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> k) {
    for (int i = 0; i < k.size(); i++) {
        cout << k[i] << " ";
    }
}

void numTilePossibilitiesHelper(vector<int> freq, int &ans) {
    for (int k = 0; k < 26; k++) {
        if (freq[k] != 0) {
            ans += 1;
            freq[k]--;
            numTilePossibilitiesHelper(freq, ans);
            freq[k]++;
        }
    }
}


int numTilePossibilities(string tiles) {
    vector<int> freq(26, 0);
    for (int i = 0; i < tiles.size(); i++) {
        freq[tiles[i] - 'A']++;
    }
    int ans = 0;
    numTilePossibilitiesHelper(freq, ans);
    return ans;
}

int main() {
    cout << numTilePossibilities("AAABBC") << "\n";
    return 0;
}
