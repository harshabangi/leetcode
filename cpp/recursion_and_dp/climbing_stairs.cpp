//
// Created by Harsha Vardhan on 24/04/22.
//

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    cout << climbStairs(3) << "\n";
    return 0;
}
