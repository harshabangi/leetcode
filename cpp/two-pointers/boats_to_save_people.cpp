//
// Created by Harsha Vardhan on 28/05/22.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());

    int i = 0, j = i + 1, ans = 0;
    while (j < people.size()) {
        if (people[i] + people[j] <= limit) {
            ans += 1;
            i
        }
    }
    return 1 + ans;
}

int main() {
    vector<int> people{1, 2, 2, 3};
    cout << numRescueBoats(people, 3) << "\n";
    return 0;
}
