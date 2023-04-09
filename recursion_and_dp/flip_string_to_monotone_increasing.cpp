//
// Created by Harsha Vardhan on 21/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minFlipsMonoIncr(string s) {
    int n = s.size();
    int countOfZeroes = 0;
    int countOfOnes = 0;
    vector<int> zeroes(n), ones(n);
    s[0] == '0' ? countOfZeroes = 1 : countOfOnes = 1;
    zeroes[0] = countOfZeroes;
    ones[0] = countOfOnes;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            countOfZeroes += 1;
            zeroes[i] = zeroes[i - 1] + 1;
        }
        if (s[i] == '1') {
            countOfOnes += 1;
            ones[i] = ones[i - 1] + 1;
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        mn = min(mn, ((i + 1) - zeroes[i]) + ((n - 1 - i) - (zeroes[n - 1] - zeroes[i])));
        mn = min(mn, ((i + 1) - zeroes[i]) + ((n - 1 - i) - (ones[n - 1] - ones[i])));
        mn = min(mn, ((i + 1) - ones[i]) + ((n - 1 - i) - (ones[n - 1] - ones[i])));
    }
    return mn;
}

int main() {

    return 0;
}
