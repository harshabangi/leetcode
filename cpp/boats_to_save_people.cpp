//
// Created by Harsha Vardhan on 05/08/22.
//

#include <iostream>
#include <vector>

using namespace std;
// 1,2,3,6,2,3,4,7,8
// 1, 2, 2, 3, 3, 4, 6, 7, 8
// 1 -> 0, 2 -> 1, 3 -> 1, 4 -> 1, 6 -> 1, 7 -> 1, 8 -> 1

int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1;
    int ans = 0;
    while (i < j) {
        if (people[i] + people[j] > limit) {
            j--;
            ans++;
        }
        if (people[i] + people[j] <= limit) {
            i++;
            j--;
            ans++;
        }
    }
    return i == j ? ans + 1 : ans;
}

int main() {
    // 1, 2, 2, 3
    vector<int> people{3, 6, 2, 4, 7, 1, 2, 9};
    cout << numRescueBoats(people, 9) << "\n";
    return 0;
}
