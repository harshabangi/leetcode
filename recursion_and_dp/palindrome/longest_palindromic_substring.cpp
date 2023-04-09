//
// Created by Harsha Vardhan on 01/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

string longestPalindromeHelper(const string &s, int i, int j) {
    cout << i << j << "\n";
    if (i == j) return to_string(s[i]);
    if (i > j) return "";
    string ans;
    if (s[i] == s[j] && isPalindrome(s.substr(i + 1, j - 1))) {
        string t = s.substr(i, j);
        if (t.size() > ans.size()) ans = t;
    }
    string a = longestPalindromeHelper(s, i + 1, j);
    string b = longestPalindromeHelper(s, i, j + 1);
    if (ans.size() > a.size()) {
        if (ans.size() > b.size()) {
            return ans;
        } else {
            return b;
        }
    } else {
        if (a.size() > b.size()) {
            return a;
        } else {
            return b;
        }
    }
}

string longestPalindrome(string s) {
    return longestPalindromeHelper(s, 0, s.size() - 1);
}

string longestPalindrome1(string s) {
    int n = s.size();
    int best_len = 0;
    string best;
    for (int mid = 0; mid < n; mid++) {
        for (int x = 0; mid - x >= 0 && mid + x < n; x++) {
            if (s[mid - x] != s[mid + x]) {
                break;
            }
            int len = 2 * x + 1;
            if (len > best_len) {
                best_len = len;
                best = s.substr(mid - x, len);
            }
        }
        for (int x = 1; mid - x + 1 >= 0 && mid + x < n; x++) {
            if (s[mid - x + 1] != s[mid + x]) {
                break;
            }
            int len = 2 * x;
            if (len > best_len) {
                best_len = len;
                best = s.substr(mid - x + 1, len);
            }
        }
    }
    return best;
}

string longestPalindrome2(string s) {
    int n = s.size();
    int best_len = 0;
    string best;
    for (int mid = 0; mid < n; mid++) {
        int k = 0;
        while (mid - k >= 0 && mid + k < n) {
            if (s[mid - k] != s[mid + k]) {
                break;
            }
            int len = 2 * k + 1;
            if (len > best_len) {
                best_len = len;
                best = s.substr(mid - k, len);
            }
            k++;
        }
        k = 1;
        while (mid - k + 1 >= 0 && mid + k < n) {
            if (s[mid - k + 1] != s[mid + k]) {
                break;
            }
            int len = 2 * k;
            if (len > best_len) {
                best_len = len;
                best = s.substr(mid - k + 1, len);
            }
            k++;
        }
    }
    return best;
}

int main() {
    string s = "baab";
    cout << longestPalindrome2(s) << "\n";
    return 0;
}
