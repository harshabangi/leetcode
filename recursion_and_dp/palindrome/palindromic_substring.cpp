//
// Created by Harsha Vardhan on 01/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int countSubstrings(string s) {
    int n = s.size();
    int ans = 0;
    for (int mid = 0; mid < n; mid++) {
        int k = 0;
        while (mid - k >= 0 && mid + k < n) {
            if (s[mid - k] != s[mid + k]) {
                break;
            }
            ans++;
            k++;
        }
        k = 1;
        while (mid - k + 1 >= 0 && mid + k < n) {
            if (s[mid - k + 1] != s[mid + k]) {
                break;
            }
            ans++;
            k++;
        }
    }
    return ans;
}

int main() {
    cout << countSubstrings("abc") << "\n";
    return 0;
}
