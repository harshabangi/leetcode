//
// Created by Harsha Vardhan on 27/07/22.
//

#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
    deque<int> dq;
    int n = answerKey.size();
    int ans = 0;
    int dupK = k;
    for (int i = 0; i < n; i++) {
        if (answerKey[i] == 'F') {
            if (dupK <= 0) {
                int size = dq.size();
                ans = max(size, ans);
                while (!dq.empty() && dq.front() == 'T') {
                    dq.pop_front();
                }
                dq.pop_front();
            } else {
                dupK--;
            }
        }
        dq.push_back(answerKey[i]);
    }
    int l = dq.size();
    ans = max(ans, l);
    dq.clear();
    dupK = k;
    for (int i = 0; i < n; i++) {
        if (answerKey[i] == 'T') {
            if (dupK <= 0) {
                int size = dq.size();
                ans = max(size, ans);
                while (!dq.empty() && dq.front() == 'F') {
                    dq.pop_front();
                }
                dq.pop_front();
            } else {
                dupK--;
            }
        }
        dq.push_back(answerKey[i]);
    }
    l = dq.size();
    ans = max(ans, l);
    return ans;
}

int main() {
    cout << maxConsecutiveAnswers("TTFF", 2) << "\n";
    return 0;
}
