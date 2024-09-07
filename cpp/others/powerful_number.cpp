//
// Created by Harsha Vardhan on 26/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int solve(int N) {
    vector<int> arr{1, 2, 4, 8, 7, 5};
    return arr[N % 6];
}

int main() {
    cout << solve(1 << 11) << "\n";
    return 0;
}
