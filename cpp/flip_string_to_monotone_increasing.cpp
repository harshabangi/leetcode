//
// Created by Harsha Vardhan on 15/07/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minFlipsMonoIncr(string s) {
    int n = s.size();
    int zeroes = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeroes += 1;
        else ones += 1;
    }
    int z = 0;
    int o = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            z += 1;
            ans = min(ans, o + (zeroes - z));
        } else {
            o += 1;
        }
    }

    z = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans = min(ans, o + (zeroes - z));
            o += 1;
        } else {
            z += 1;
        }
    }
    //00000010010000001000
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << minFlipsMonoIncr(s) << "\n";
    return 0;
}
