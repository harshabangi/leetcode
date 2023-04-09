//
// Created by Harsha Vardhan on 03/06/22.
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

bool isEqual(unordered_map<char, int> &sMap, unordered_map<char, int> &tMap) {
    for (auto it: sMap) {
        if (tMap.find(it.first) == tMap.end()) return false;
        if (tMap[it.first] != it.second) return false;
    }
    for (auto it: tMap) {
        if (sMap.find(it.first) == sMap.end()) return false;
        if (sMap[it.first] != it.second) return false;
    }
    return true;
}

string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";
    unordered_map<char, int> tMap, sMap;
    for (int i = 0; i < t.size(); i++) {
        tMap[t[i]]++;
    }
    deque<pair<char, int>> dq;
    int best_len = INT_MAX;
    string best;
    for (int i = 0; i < s.size(); i++) {
        if (tMap.find(s[i]) != tMap.end()) {
            if (sMap.find(s[i]) != sMap.end()) {

            } else {
                sMap[s[i]]++;
            }
        }
        if (isEqual(sMap, tMap)) {
            pair<char, int> front = dq.front();
            int len = i - front.second;
            if (len < best_len) {
                best_len = len;
                best = s.substr(i, i - front.second);
            }
            dq.pop_front();
            sMap[front.first]--;
            if (sMap[front.first] == 0) sMap.erase(front.first);
        }
        dq.emplace_back(s[i], i);
    }
    return best;
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << "\n";
    return 0;
}
