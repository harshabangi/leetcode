//
// Created by Harsha Vardhan on 02/07/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<char> c{'a', 'b', 'c'};

void getHappyStringHelper(int n, int k, string s, char prev, string &ans, int &t) {
    priority_queue<int> pq;
    if (n == 0) {
        t += 1;
        if (k == t) {
            ans = s;
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (prev != c[i]) {
            getHappyStringHelper(n - 1, k, s + c[i], c[i], ans, t);
        }
    }
}

string getHappyString(int n, int k) {
    string ans;
    int t = 0;
    getHappyStringHelper(n, k, "", ' ', ans, t);
    return ans;
}

int main() {
    cout << getHappyString(3, 9) << "\n";
    return 0;
}
