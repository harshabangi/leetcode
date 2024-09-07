//
// Created by Harsha Vardhan on 21/08/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int toDigit(char c) {
    return c - '0';
}

string largestPalindromic(string num) {
    vector<int> s(10, 0);
    for (int i = 0; i < num.size(); i++) {
        s[toDigit(num[i])]++;
    }

    int maxOddInt = INT_MIN;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] % 2 != 0) {
            maxOddInt = i;
            break;
        }
    }

    string ans;
    for (int i = s.size() - 1; i >= 0; i--) {
        if ((s[i] != 0 && s[i] % 2 == 0) || (s[i] != 0 && s[i] % 2 != 0 && s[i] > 1)) {
            int l = s[i] / 2;
            for (int j = 0; j < l; j++) {
                ans += to_string(i);
            }

        }
    }
    if (maxOddInt != INT_MIN) {
        ans += to_string(maxOddInt);
    }

    for (int i = 0; i < s.size(); i++) {
        if ((s[i] != 0 && s[i] % 2 == 0) || (s[i] != 0 && s[i] % 2 != 0 && s[i] > 1)) {
            int l = s[i] / 2;
            for (int j = 0; j < l; j++) {
                ans += to_string(i);
            }
        }
    }

    string ans_c;
    int i = 0, c = 0, j;
    while (i < ans.size()) {
        if (ans[i] == '0') {
            i++;
            c++;
        } else break;
    }
    if (c == 0) return ans;
    else {
        i = c;
        j = ans.size() - c - 1;
        while (i <= j) {
            ans_c += ans[i];
            i++;
        }
    }
    return ans_c.size() == 0 ? "0" : ans_c;
}

int main() {
    cout << largestPalindromic("0069600") << "\n";
    return 0;
}
