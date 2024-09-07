//
// Created by Harsha Vardhan on 20/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

int edgeScore(vector<int> &edges) {
    int n = edges.size();
    vector<long long> incoming(n, 0);
    for (int i = 0; i < n; i++) {
        incoming[edges[i]] += i;
    }
    int maxEdge = 0;
    long long score = LONG_LONG_MIN;
    for (int i = 0; i < n; i++) {
        if (incoming[i] > score) {
            score = incoming[i];
            maxEdge = i;
        }
    }
    return maxEdge;
}

int main() {
    vector<int> edges{1, 0, 0, 0, 0, 7, 7, 5};
    cout << edgeScore(edges) << "\n";
    return 0;
}
