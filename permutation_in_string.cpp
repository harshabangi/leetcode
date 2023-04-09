//
// Created by Harsha Vardhan on 22/05/22.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void print(vector<int> &freq) {
    for (int i = 0; i < freq.size(); i++) {
        cout << freq[i] << " ";
    }
    cout << "\n";
}

bool Equal(vector<int> &freq1, vector<int> &freq2) {
    for (int i = 0; i < freq1.size(); i++) {
        if (freq1[i] != freq2[i]) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2) return false;
    vector<int> freq1(26, 0);
    for (int i = 0; i < n1; i++) {
        freq1[s1[i] - 'a']++;
    }

    vector<int> freq2(26, 0);
    deque<char> dq;

    for (int i = 0; i < n1; i++) {
        dq.push_back(s2[i]);
        freq2[s2[i] - 'a']++;
    }

    for (int i = n1; i < n2; i++) {
        if (Equal(freq1, freq2)) return true;
        freq2[dq.front() - 'a'] -= 1;
        dq.pop_front();
        freq2[s2[i] - 'a'] += 1;
        dq.push_back(s2[i]);
    }
    return Equal(freq1, freq2);
}

int main() {
    string s1 = "adc", s2 = "dcda";
    cout << checkInclusion(s1, s2) << "\n";
    return 0;
}