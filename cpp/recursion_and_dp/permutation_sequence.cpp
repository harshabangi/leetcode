//
// Created by Harsha Vardhan on 23/01/22.
//

#include <iostream>
#include <vector>

using namespace std;


string getPermutationHelper(int n, int k, int fact, string ans) {
    int z = fact / n;
    getPermutationHelper(n - 1, k - z, z, ans + to_string(z));
    return "";
}

string getPermutation(int n, int k) {
    vector<bool> freq(n + 1, false);
    return getPermutationHelper(n, k, "", freq);
}

int main() {
    cout << getPermutation(3, 3) << "\n";
    return 0;
}