//
// Created by Harsha Vardhan on 12/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int numSquaresHelper(vector<int> &memo, int n, int d) {
    if (n == 0) return 0;
    if (n < 0) return 1e9;
    if (memo[n] != -1) return memo[n];
    int ans = 1e9;
    for (int i = 1; i <= d; i++) {
        ans = min(ans, 1 + numSquaresHelper(memo, n - i * i, d));
    }
    return memo[n] = ans;
}

int numSquares(int n) {
    int i = 1, k = 0;
    while (k < n) {
        i++;
        k = i * i;
    }
    vector<int> memo(n + 1, -1);
    return numSquaresHelper(memo, n, i - 1);
}

int main() {
    cout << numSquares(12) << "\n";
    return 0;
}
