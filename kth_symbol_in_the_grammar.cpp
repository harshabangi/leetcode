//
// Created by Harsha Vardhan on 22/01/22.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

string kth_grammar_helper(int n) {
    if (n == 1) return "0";
    string z = kth_grammar_helper(n-1);
    string k = "";
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == '0') k += '1';
        else k += '0';
    }
    return z + k;
}

int kth_grammar(int n, int k) {
    if (n == 1 && k == 1) return 0;
    int mid = pow(2, n-1) / 2;
    if (k <= mid) {
        return kth_grammar(n-1, k);
    } else {
        return !kth_grammar(n-1, k-mid);
    }
}

int main() {
    cout << kth_grammar_helper(30);
    return 0;
}