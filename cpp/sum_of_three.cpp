//
// Created by Harsha Vardhan on 19/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

// 2, 4, 6, 8, 10

vector<long long> sumOfThree(long long num) {
    vector<long long> ans;
    if (num % 3 == 0) {
        long long k = num / 3;
        ans.push_back(k - 1);
        ans.push_back(k);
        ans.push_back(k + 1);
    }
    return ans;
}

int main() {
    vector<long long> ans = sumOfThree(4);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}