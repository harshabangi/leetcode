//
// Created by Harsha Vardhan on 04/06/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct comparator {
    bool operator()(pair<string, int> &a, pair<string, int> &b) {
        if (a.second == b.second) {
            for (int i = 0; i < min(a.first.size(), b.first.size()); i++) {
                if (a.first[i] == b.first[i]) continue;
                else return a.first[i] < b.first[i];
            }
            return a.first.size() < b.first.size();
        } else {
            return a.second < b.second;
        }
    }
};

int getNumberOfWords(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            count += 1;
        }
    }
    return count + 1;
}

string largestWordCount(vector<string> &messages, vector<string> &senders) {
    priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;
    unordered_map<string, int> umap;
    for (int i = 0; i < messages.size(); i++) {
        umap[senders[i]] += getNumberOfWords(messages[i]);
    }
    for (auto it: umap) {
        pq.push({it.first, it.second});
    }
    return pq.top().first;
}

int main() {
    return 0;
}
