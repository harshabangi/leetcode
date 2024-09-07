//
// Created by Harsha Vardhan on 26/05/22.
//

#include <iostream>
#include <vector>

using namespace std;


int countVowelPermutationHelper(int n, char c) {
    if (n == 0) return 0;
    int ans = 0;
    if (c == 'a') {
        ans = 1 + countVowelPermutationHelper(n - 1, 'e');
    } else if (c == 'e') {
        ans = 1 + countVowelPermutationHelper(n - 1, 'a') +
              countVowelPermutationHelper(n - 1, 'i');
    } else if (c == 'i') {
        ans = 1 + countVowelPermutationHelper(n - 1, 'a') +
              countVowelPermutationHelper(n - 1, 'e') +
              countVowelPermutationHelper(n - 1, 'o') +
              countVowelPermutationHelper(n - 1, 'u');
    } else if (c == 'o') {
        ans = 1 + countVowelPermutationHelper(n - 1, 'i') +
              countVowelPermutationHelper(n - 1, 'u');
    } else {
        ans = 1 + countVowelPermutationHelper(n - 1, 'a');
    }
    return ans;
}

int countVowelPermutation(int n) {
    return 5 + countVowelPermutationHelper(n, 'a') + countVowelPermutationHelper(n, 'e')
    + countVowelPermutationHelper(n, 'i') + countVowelPermutationHelper(n, 'o') + countVowelPermutationHelper(n, 'u');
}

int main() {
    cout << countVowelPermutation(2) << "\n";
    return 0;
}
