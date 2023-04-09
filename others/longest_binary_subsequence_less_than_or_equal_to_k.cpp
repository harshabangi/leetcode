//
// Created by Harsha Vardhan on 25/06/22.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int longestSubsequence(string s, int k) {
    int n = s.size();
    int ans = 0;
    int sum = 0;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            ans++;
            continue;
        } else {
            if (!flag) {
                sum += pow(2, ans);
                if (sum <= k) {
                    ans++;
                } else {
                    flag = true;
                }
            }
        }
    }
    return ans;
}

int main() {
    string s = "001010101011010100010101101010010";
    int k = 93951055;
    cout << longestSubsequence(s, k) << "\n";
    return 0;
}