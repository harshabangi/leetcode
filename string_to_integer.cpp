//
// Created by Harsha Vardhan on 01/01/22.
//

#include <iostream>
#include <cmath>

using namespace std;

string remove_empty_string(string t) {
    string a = "";
    bool flag = true;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == ' ' && !flag) {
            break;
        }
        if (t[i] != ' '){
            a += t[i];
            flag = false;
        }
    }
    cout << "A: " << a << "\n";
    return a;
}

string remove_first_set_of_zeroes(string s) {
    bool flag = true;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0' && flag) {
            // Do nothing
        } else {
            tmp += s[i];
            flag = false;
        }
    }
    return tmp;
}

int string_to_int(string s) {
    bool isNegative = false;
    s = remove_empty_string(s);
    cout << s << "\n";

    string tmp = "";
    int k = 0;
    if (s[0] == '-') {
        k = 1;
        isNegative = true;
    } else if (s[0] == '+') {
        k = 1;
    }
    for (int i = k; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            tmp += s[i];
        } else {
            break;
        }
    }
    tmp = remove_first_set_of_zeroes(tmp);
    int n = tmp.size() - 1;
    long total = 0;
    cout << tmp << "\n";
    long mn = -pow(2, 31);
    long mx = pow(2, 31) - 1;

    for (int i = n; i >= 0; i--) {
        cout << tmp[i] - '0' << "\n";
        total += (tmp[i] - '0') * pow(10, n - i);
    }
    long z = isNegative ? -total : total;
    cout << z << "\n";
    if (z < mn) {
        return mn;
    } else if (z > mx) {
        return mx;
    } else {
        return z;
    }
}

int main() {
    cout << string_to_int("   +4.898989 123") << "\n";
    return 0;
}