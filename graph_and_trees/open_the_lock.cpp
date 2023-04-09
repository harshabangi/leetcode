//
// Created by Harsha Vardhan on 30/10/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;



/*
 * 0000
 * 8888
 *
 * 6767
 * "8887", "8878", "8788", "7888"
 * "8889", "8898", "8988", "9888"
 *
 * 8888 => ()
 *
 * */

int toDigit(char c) {
    return c - '0';
}

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int openLock(vector<string> &deadends, string target) {
    unordered_set<string> uset, visited;

    for (int i = 0; i < deadends.size(); i++) {
        uset.insert(deadends[i]);
    }
    if (uset.find(target) != uset.end() || uset.find("0000") != uset.end()) {
        return -1;
    }
    if (target == "0000") return 0;

    queue<string> q;
    q.push("0000");
    visited.insert("0000");
    int count = 0;

    while (!q.empty()) {
        int size = q.size();
        count++;

        for (int i = 0; i < size; i++) {
            string top = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {

                string l = top;
                int k = (toDigit(l[j]) + 1) % 10;
                l[j] = digits[k];

                if (l == target) {
                    return count;
                }

                if (uset.find(l) == uset.end() && visited.find(l) == visited.end()) {
                    q.push(l);
                    visited.insert(l);
                }
            }

            for (int j = 0; j < 4; j++) {
                string l = top;
                int k = toDigit(l[j]);
                if (k == 0) {
                    k = 9;
                } else {
                    k -= 1;
                }
                l[j] = digits[k];

                if (l == target) {
                    return count;
                }
                if (uset.find(l) == uset.end() && visited.find(l) == visited.end()) {
                    q.push(l);
                    visited.insert(l);
                }
            }

        }
    }
    return -1;
}

int main() {
    return 0;
}
