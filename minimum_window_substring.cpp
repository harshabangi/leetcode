//
// Created by Harsha Vardhan on 01/01/22.
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool compare(vector<int> a1, vector<int> a2) {
    for (int i = 0; i < 26; i++) {
        if (a1[i] != a2[i]) return false;
    }
    return true;
}

int main() {
    return 0;
}
