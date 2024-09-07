//
// Created by Harsha Vardhan on 31/12/21.
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

vector<int> findAnagrams(string s, string p) {
    deque<char> dq;
    vector<int> ans;
    if (p.size() > s.size()) return ans;
    int n = p.size();
    vector<int> tmp(26, 0);
    vector<int> ideal(26, 0);

    for (int i = 0; i < n; i++) {
        ideal[p[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        tmp[s[i] - 'a']++;
        dq.push_back(s[i]);
    }

    if (compare(tmp, ideal)) ans.push_back(0);
    for (int i = n; i < s.size(); i++) {
        char front = dq.front();
        dq.pop_front();
        tmp[front - 'a']--;
        dq.push_back(s[i]);
        tmp[s[i] - 'a']++;
        if (compare(tmp, ideal)) ans.push_back(i-n+1);
    }
    return ans;
}

int main() {
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = findAnagrams(s, p);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}