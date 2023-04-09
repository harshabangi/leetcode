//
// Created by Harsha Vardhan on 11/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * 0 1 2 3 4 5 6 7
 * a a c e c a a a
 *
 * TLE
*/

string shortestPalindrome(string s) {
    int n = s.size();
    int b = n % 2 == 0 ? n / 2 - 1 : n / 2;
    string best;
    int bestlen = INT_MAX;
    for (int mid = 0; mid <= b; mid++) {
        int k = 0;
        while (mid - k >= 0 && mid + k < n) {
            if (s[mid + k] != s[mid - k]) break;
            k++;
        }
        if (mid - k == -1 && mid + k == n) return s;
        if (mid - k == -1) {
            int t = n - (mid + k);
            if (t < bestlen) {
                bestlen = t;
                best = s.substr(mid + k, t);
            }
        }
        k = 1;
        while (mid - k + 1 >= 0 && mid + k < n) {
            if (s[mid - k + 1] != s[mid + k]) break;
            k++;
        }
        if (mid - k + 1 == -1 && mid + k == n) return s;
        if (mid - k + 1 == -1) {
            int t = n - (mid + k);
            if (t < bestlen) {
                bestlen = t;
                best = s.substr(mid + k, t);
            }
        }
    }
    reverse(best.begin(), best.end());
    return best + s;
}

int main() {
    string s = "aacecaaa";
    cout << shortestPalindrome("aba") << "\n";
    return 0;
}
