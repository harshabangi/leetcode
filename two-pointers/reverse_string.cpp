//
// Created by Harsha Vardhan on 28/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<char> &s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void reverseString(vector<char> &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        swap(s, i, j);
        i++;
        j--;
    }
}

int main() {
    return 0;
}
