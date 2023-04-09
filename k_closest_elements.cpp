//
// Created by Harsha Vardhan on 13/04/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct P {
    int i1;
    int i2;
};

struct comparator {
    bool operator()(const P a, const P b) {
        int diffA = abs(a.i1 - a.i2);
        int diffB = abs(b.i1 - b.i2);
        if (diffA > diffB) return true;
        if (diffA == diffB) {
            if (a.i1 > b.i1) return true;
            else return false;
        } else return false;
    };
};


struct comparator1 {
    bool operator()(const P a, const P b) {
        int diffA = abs(a.i1 - a.i2);
        int diffB = abs(b.i1 - b.i2);
        if (diffA != diffB) {
            return diffA > diffB;
        }
        return a.i1 > b.i1;
    };
};

vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    vector<P> a(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        a[i] = P{arr[i], x};
    }
    priority_queue<P, vector<P>, comparator1> pq;
    for (int i = 0; i < arr.size(); i++) {
        pq.push(a[i]);
    }
    vector<int> ans(k);
    for (int i = 0; i < k; i++) {
        ans[i] = pq.top().i1;
        pq.pop();
    }
//    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr{
            0, 0, 1, 2, 3, 3, 4, 7, 7, 8
    };
    int k = 3, x = 5;
    vector<int> ans = findClosestElements(arr, k, x);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
