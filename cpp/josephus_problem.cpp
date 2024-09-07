//
// Created by Harsha Vardhan on 16/01/22.
//

#include <iostream>
#include <queue>

using namespace std;

int find_the_winner(int n, int k) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        int count = k-1;
        while (count > 0) {
            q.push(q.front());
            q.pop();
            count--;
        }
        q.pop();
    }
    return q.front();
}
int main() {
    cout << find_the_winner(5, 2) << "\n";
    return 0;
}