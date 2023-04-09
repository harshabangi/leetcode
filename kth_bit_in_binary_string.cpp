//
// Created by Harsha Vardhan on 31/12/21.
//

#include <iostream>
using namespace std;

string invert(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') ans += "1";
        else ans += "0";
    }
    return ans;
}

string reverse(string s) {
    string ans = "";
    for (int i = s.size()-1; i >= 0; i--) {
        ans += s[i];
    }
    return ans;
}

string find_kth_bit(int n, int k) {
    if (n == 1) return "0";
    string tmp = find_kth_bit(n - 1, k);
    return tmp + "1" +  reverse(invert(tmp));
}

int main() {
    cout << find_kth_bit(4, 3) << "\n";
}