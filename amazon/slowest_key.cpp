//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comparator {
    bool operator()(const pair<int, char> a, const pair<int, char> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
};

char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    priority_queue<pair<int, char>, vector<pair<int, char>>, comparator> pq;
    pq.push({releaseTimes[0], keysPressed[0]});
    for (int i = 1; i < releaseTimes.size(); i++) {
        pq.push({releaseTimes[i] - releaseTimes[i - 1], keysPressed[i]});
    }
    return pq.top().second;
}

int main() {
    vector<int> releaseTimes{9,29,49,50};
    string keysPressed = "cbcd";
    cout << slowestKey(releaseTimes, keysPressed) << "\n";
    return 0;
}
