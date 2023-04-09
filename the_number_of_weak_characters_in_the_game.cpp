//
// Created by Harsha Vardhan on 08/08/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int numberOfWeakCharacters(vector<vector<int>> &properties) {
    unordered_set<int> attackSet;
    vector<pair<int, int>> attacks;
    unordered_map<int, int> attackToDefense;
    for (int i = 0; i < properties.size(); i++) {
        if (attackSet.find(properties[i][0]) == attackSet.end()) {
            attacks.emplace_back(properties[i][0], 0);
            attackSet.insert(properties[i][0]);
        }
        if (attackToDefense.find(properties[i][0]) != attackToDefense.end()) {
            attackToDefense[properties[i][0]] = max(attackToDefense[properties[i][0]], properties[i][1]);
        } else {
            attackToDefense[properties[i][0]] = properties[i][1];
        }
    }
    sort(attacks.begin(), attacks.end());

    int maxAttack = attacks[attacks.size() - 1].first;

    for (int i = 0; i < attacks.size(); i++) {
        attacks[i].second = attackToDefense[attacks[i].first];
    }

    int l = attacks[attacks.size() - 1].second;
    for (int i = attacks.size() - 2; i >= 0; i--) {
        int k = attacks[i].second;
        attacks[i].second = l;
        l = max(l, k);
    }
    for (int i = 0; i < attacks.size(); i++) {
        attackToDefense[attacks[i].first] = attacks[i].second;
    }
    int ans = 0;
    for (int i = 0; i < properties.size(); i++) {
        if (maxAttack != properties[i][0] && properties[i][1] < attackToDefense[properties[i][0]]) ans++;
    }
    return ans;
}

int main() {
    vector<vector<int>> properties{
            {1,  5},
            {10, 4},
            {4,  3}
    };
    cout << numberOfWeakCharacters(properties) << "\n";
    return 0;
}
