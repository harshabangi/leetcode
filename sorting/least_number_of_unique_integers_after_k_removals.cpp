//
// Created by Harsha Vardhan on 04/10/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    unordered_map<int, int> umap;
    for (int i = 0; i < arr.size(); i++) {
        umap[arr[i]]++;
    }
    vector<vector<int>> arrD;
    for (auto it: umap) {
        arrD.push_back({it.second, it.first});
    }
    sort(arrD.begin(), arrD.end());
    int l = umap.size(), i = 0;

    while (k > 0) {
        if (arrD[i][0] <= k) {
            k -= arrD[i][0];
            l--;
            i++;
        } else {
            break;
        }
    }
    return l;
}

int main() {
    vector<int> arr {4,3,1,1,3,3,2};
    int k = 3;
    cout << findLeastNumOfUniqueInts(arr, k) << "\n";
    return 0;
}
