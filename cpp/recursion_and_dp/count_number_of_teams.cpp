//
// Created by Harsha Vardhan on 17/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numTeamsHelperAscending(vector<int> &rating, int n, int idx, vector<vector<int>> &dpAsc) {
    if (n == 0) {
        return 1;
    }
    if (dpAsc[idx][n] != -1) return dpAsc[idx][n];
    int ans = 0;
    for (int i = idx + 1; i < rating.size(); i++) {
        if (rating[i] > rating[idx]) {
            ans += numTeamsHelperAscending(rating, n - 1, i, dpAsc);
        }
    }
    return dpAsc[idx][n] = ans;
}

int numTeamsHelperDescending(vector<int> &rating, int n, int idx, vector<vector<int>> &dpDesc) {
    if (n == 0) {
        return 1;
    }
    if (dpDesc[idx][n] != -1) return dpDesc[idx][n];
    int ans = 0;
    for (int i = idx + 1; i < rating.size(); i++) {
        if (rating[i] < rating[idx]) {
            ans += numTeamsHelperDescending(rating, n - 1, i, dpDesc);
        }
    }
    return dpDesc[idx][n] = ans;
}

int numTeams(vector<int> &rating) {
    int ans = 0;
    int n = rating.size();
    vector<vector<int>> dpAsc(n + 1, vector<int>(3, -1));
    vector<vector<int>> dpDesc(n + 1, vector<int>(3, -1));
    unordered_map<string, int> umap;
    for (int i = 0; i < rating.size() - 2; i++) {
        ans += numTeamsHelperAscending(rating, 2, i, dpAsc);
        ans += numTeamsHelperDescending(rating, 2, i, dpDesc);
    }
    return ans;
}

int main() {
    vector<int> rating{1, 4, 2, 5};
    cout << numTeams(rating) << "\n";
    return 0;
}
