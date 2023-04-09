//
// Created by Harsha Vardhan on 26/05/22.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void swap(string &s, int i, int j) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
}

void reverse(string &s, int i, int j) {
    while (i < j) {
        swap(s, i, j);
        i++;
        j--;
    }
}

int nextGreaterElement(int n) {
    string s = to_string(n);
    int i = s.size() - 2;
    while (i >= 0) {
        if (s[i] < s[i + 1]) {
            break;
        }
        i--;
    }
    if (i == -1) return -1;
    int j = s.size() - 1;
    while (j >= 0) {
        if (s[j] > s[i]) {
            break;
        } else {
            j--;
        }
    }
    swap(s, i, j);
    reverse(s, i + 1, s.size() - 1);

    long long ans = 0, l = 0;
    for (int k = s.size()-1; k >= 0; k--) {
        ans += (s[k] - '0') * pow(10, l);
        l++;
    }
    return ans > INT_MAX ? -1 : ans;
}

int main() {
    cout << nextGreaterElement(2147483486) << "\n";
    return 0;
}