//
// Created by Harsha Vardhan on 01/03/22.
//

#include <iostream>
#include <vector>

using namespace std;

struct SL {
    string s;
    int len;
    int mask;

    SL(string s, int len, int mask) : s(s), len(len), mask(mask) {};
};

int calculate_mask(string s) {
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        k += (1 << (s[i] - 'a'));
    }
    return k;
}

void maxLengthHelper(vector<SL> sl, int &res, int tmp, int x, int idx) {
    if (x > res) {
        res = x;
    }
    for (int i = idx; i < sl.size(); i++) {
        tmp = tmp & sl[i].mask;
        if (tmp == 0) {
            x += sl[i].len;
        }
        maxLengthHelper(sl, res, tmp, x, i + 1);
    }
}

int maxLength(vector<string> &arr) {
    vector<SL> sl;
    for (int i = 0; i < arr.size(); i++) {
        int t = arr[i].size();
        sl.emplace_back(arr[i], t, calculate_mask(arr[i]));
    }
    int res = 0;
    maxLengthHelper(sl, res, 1, 0, 0);
    return res;
}

int main() {
    vector<string> arr{"un", "iq", "ue"};
    int max_length = maxLength(arr);
    cout << max_length << "\n";
    return 0;
}

