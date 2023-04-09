//
// Created by Harsha Vardhan on 04/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
    vector<int> remCapacity(rocks.size());
    for (int i = 0; i < rocks.size(); i++) {
        remCapacity[i] = capacity[i] - rocks[i];
    }
    sort(remCapacity.begin(), remCapacity.end());
    int ans = 0;
    for (int i = 0; i < remCapacity.size(); i++) {
        if (remCapacity[i] == 0) ans++;
        else {
            if (additionalRocks >= remCapacity[i]) {
                additionalRocks -= remCapacity[i];
                ans++;
            } else {
                return ans;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
