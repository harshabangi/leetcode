//
// Created by Harsha Vardhan on 11/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool isRobotBounded(string instructions) {
    int x = 0, y = 0;
    char facing = 'N';
    for (int i = 0; i < instructions.size(); i++) {
        if (instructions[i] == 'G') {
            if (facing == 'N') {
                y += 1;
            } else if (facing == 'S') {
                y -= 1;
            } else if (facing == 'W') {
                x -= 1;
            } else {
                x += 1;
            }
        } else if (instructions[i] == 'L') {
            if (facing == 'N') {
                facing = 'W';
            } else if (facing == 'S') {
                facing = 'E';
            } else if (facing == 'W') {
                facing = 'S';
            } else {
                facing = 'N';
            }
        } else {
            if (facing == 'N') {
                facing = 'E';
            } else if (facing == 'S') {
                facing = 'W';
            } else if (facing == 'W') {
                facing = 'N';
            } else {
                facing = 'S';
            }
        }
    }
    return (x == 0 && y == 0) || facing != 'N';
}

int main() {
    string instruction = "GGLLGG";
    cout << isRobotBounded(instruction) << "\n";
    return 0;
}
