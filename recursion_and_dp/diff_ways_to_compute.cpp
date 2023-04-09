//
// Created by Harsha Vardhan on 22/01/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> diff_ways_to_compute(string expression) {
    vector<int>res;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            vector<int> first = diff_ways_to_compute(expression.substr(0, i));
            vector<int> second = diff_ways_to_compute(expression.substr(i + 1));
            for (int j = 0; j < first.size(); j++) {
                for (int k = 0; k < second.size(); k++) {
                    if (expression[i] == '+') {
                        res.push_back(first[j] + second[k]);
                    } else if (expression[i] == '-') {
                        res.push_back(first[j] - second[k]);
                    } else {
                        res.push_back(first[j] * second[k]);
                    }
                }
            }
        }
    }
    if (res.empty()) res.push_back(stoi(expression));
    return res;
}

int main() {
    vector<int> ans = diff_ways_to_compute("5*3-2*3");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}