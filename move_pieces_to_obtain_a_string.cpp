//
// Created by Harsha Vardhan on 27/07/22.
//

#include<iostream>
#include <vector>

using namespace std;

bool canChange(string start, string target) {
    if (start.size() != target.size()) return false;
    int targetsFirstR = -1, targetsFirstL = -1, startFirstR = -1, startFirstL = -1;
    int targetsLastR = -1, targetsLastL = -1, startLastR = -1, startLastL = -1;
    int targetCountR = 0, targetCountL = 0, startCountR = 0, startCountL = 0;

    int startSize = start.size(), targetSize = target.size();
    for (int i = startSize - 1; i >= 0; i--) {
        if (start[i] == 'R') {
            startCountR++;
            startFirstR = i;
        }
        if (start[i] == 'L') {
            startCountL++;
            startFirstL = i;
        }

        if (start[startSize - 1 - i] == 'R') {
            startLastR = startSize - 1 - i;
        }
        if (start[startSize - 1 - i] == 'L') {
            startLastL = startSize - 1 - i;
        }

    }
    for (int i = targetSize - 1; i >= 0; i--) {
        if (target[i] == 'R') {
            targetCountR++;
            targetsFirstR = i;
        }
        if (target[i] == 'L') {
            targetCountL++;
            targetsFirstL = i;
        }

        if (target[targetSize - 1 - i] == 'R') {
            targetsLastR = targetSize - 1 - i;
        }
        if (target[targetSize - 1 - i] == 'L') {
            targetsLastL = targetSize - 1 - i;
        }
    }
    if (startCountL != targetCountL) return false;
    if (startCountR != targetCountR) return false;
    if (targetsFirstR < startFirstR) return false;
    if (targetsFirstL > startFirstL) return false;
    if (targetsLastL > startLastL) return false;
    if (targetsLastR < startLastR) return false;

    string pruneStart, pruneTarget;
    for (int i = 0; i < start.size(); i++) {
        if (start[i] != '_') {
            pruneStart += start[i];
        }
        if (target[i] != '_') {
            pruneTarget += target[i];
        }
    }
    return pruneStart.compare(pruneTarget) == 0;
}

int main() {
    return 0;
}
