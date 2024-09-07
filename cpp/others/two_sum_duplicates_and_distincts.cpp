//
// Created by Harsha Vardhan on 16/06/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> findPairs(vector<int> arr, int target) {
    //4, 1, 2, 3, 2, 4
    unordered_map<int, int> umap;
    for (int i = 0; i < arr.size(); i++) {
        umap[arr[i]]++;
    }
    vector<pair<int, int>> results;
    for (int i = 0; i < arr.size(); i++) {
        int diff = target - arr[i];
        umap[arr[i]]--;
        if (umap.find(diff) != umap.end() && umap[diff] >= 1) {
            results.push_back({arr[i], diff});
            umap[diff]--;
        }
    }
    return results;
}

vector<pair<int, int>> findDistinctPairs(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    vector<pair<int, int>> result;
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        while (i > 0 && arr[i] == arr[i - 1] && i < j) i++;
        while (j > arr.size() + 1 && arr[j] == arr[j + 1] && i < j) j--;

        if (i >= j) break;

        int sum = arr[i] + arr[j];
        if (sum == target) {
            result.push_back(make_pair(arr[i], arr[j]));
            i++;
            j--;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return result;
}

int main() {
    vector<int> arr{2, 1, 3, 2, 4, 3, 4, 2};
    vector<pair<int, int>> ans = findPairs(arr, 6);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ", " << ans[i].second << "\n";
    }
    return 0;
}
