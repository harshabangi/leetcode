//
// Created by Harsha Vardhan on 01/01/22.
//

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

bool bfs(int x1, int x2, int t) {
    queue<int> q;
    unordered_set<int> uset;
    q.push(0);
    uset.insert(0);
    while (!q.empty()) {
        int size = q.size();
        int k = q.front();
        q.pop();
        if (k == t) return true;
        for (int i = 0; i < size; i++) {
            if (uset.find(k + x1) == uset.end()) {
                uset.insert(k + x1);
                q.push(k + x1);
            }
            if (uset.find(k - x1) == uset.end()) {
                uset.insert(k - x1);
                q.push(k - x1);
            }
            if (uset.find(k + x2) == uset.end()) {
                uset.insert(k + x2);
                q.push(k + x2);
            }
            if (uset.find(k - x2) == uset.end()) {
                uset.insert(k - x2);
                q.push(k - x2);
            }
        }
    }
    return false;
}

int main() {
//    cout << graph_and_trees(3, 5, 4) << "\n";
//    cout << graph_and_trees(2, 6, 5) << "\n";
    cout << bfs(1, 2, 3) << "\n";
    return 0;
}
