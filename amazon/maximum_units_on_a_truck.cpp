//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <queue>

using namespace std;

bool comparator(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    int i = 0, ans = 0;
    while (truckSize > 0 && i < boxTypes.size()) {
        if (boxTypes[i][0] < truckSize) {
            truckSize -= boxTypes[i][0];
            ans += (boxTypes[i][0] * boxTypes[i][1]);
        } else {
            ans += (truckSize * boxTypes[i][1]);
            truckSize = 0;
        }
        i++;
    }
    return ans;
}

int main() {
    vector<vector<int>> boxTypes{
            {1, 3},
            {2, 2},
            {3, 1}
    };
    int truckSize = 4;
    cout << maximumUnits(boxTypes, truckSize) << "\n";
    return 0;
}
