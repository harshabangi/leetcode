//
// Created by Harsha Vardhan on 20/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

void RecPermute(string soFar, string rest) {
    if (rest.empty()) {
        cout << soFar << endl;
    } else {
        for (int i = 0; i < rest.length(); i++) {
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(soFar + rest[i], remaining);
        }
    }
}

int main() {
    string s = "abc";
    cout << s.substr(1) << "\n";
    RecPermute("", "abc");
    return 0;
}
