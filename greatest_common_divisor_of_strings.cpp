//
// Created by Harsha Vardhan on 30/04/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int gcd(int x, int y) {
    while (x != y) {
        if (x > y) x -= y;
        else y -= x;
    }
    return x;
}

string gcdOfStrings(string str1, string str2) {
    int s1 = str1.size();
    int s2 = str2.size();
    return str1 + str2 == str2 + str1 ? str1.substr(0, gcd(s1, s2)) : "";
}

int main() {
    string str1 = "ABABABAB";
    string str2 = "ABAB";
//    gcdOfStrings(str1, str2);
    cout << gcdOfStrings(str1, str2) << "\n";
    return 0;
}
