//
// Created by Harsha Vardhan on 08/06/22.
//

#include <iostream>
#include <vector>

using namespace std;


void findMinFibonacciNumbersHelper(vector<int> &fib, int k, bool &flag, int &ans, int count, int idx) {
    if (k == 0) {
        flag = true;
        ans = count;
        return;
    }
    if (k < 0) {
        return;
    }
    for (int i = idx; i >= 0; i--) {
        if (!flag) {
            findMinFibonacciNumbersHelper(fib, k - fib[i], flag, ans, count + 1, i);
        }
    }
}

int findMinFibonacciNumbers(int k) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);

    int m = 1;
    int n = 1;
    while (m + n <= k) {
        int tmp = m + n;
        fib.push_back(m + n);
        m = n;
        n = tmp;
    }
    for (int i = 0; i < fib.size(); i++) {
        cout << fib[i] << "\n";
    }
    int ans;
    bool flag = false;
    findMinFibonacciNumbersHelper(fib, k, flag, ans, 0, fib.size() - 1);
    return ans;
}

int main() {
    cout << findMinFibonacciNumbers(5) << "\n";
    return 0;
}
