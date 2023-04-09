//
// Created by Harsha Vardhan on 21/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int mincostTicketsHelper(vector<int> &costs, unordered_set<int> &uset, int nthDay, int &finalDay) {
    cout << nthDay << "\n";
    if (nthDay > finalDay) return 0;
    int a, b, c;
    if (uset.find(nthDay) != uset.end()) {
        a = costs[0] + mincostTicketsHelper(costs, uset, nthDay + 1, finalDay);
        b = costs[1] + mincostTicketsHelper(costs, uset, nthDay + 7, finalDay);
        c = costs[2] + mincostTicketsHelper(costs, uset, nthDay + 30, finalDay);
    } else {
        a = min(costs[0] + mincostTicketsHelper(costs, uset, nthDay + 1, finalDay),
                mincostTicketsHelper(costs, uset, nthDay + 1, finalDay));
        b = min(costs[1] + mincostTicketsHelper(costs, uset, nthDay + 7, finalDay),
                mincostTicketsHelper(costs, uset, nthDay + 1, finalDay));
        c = min(costs[2] + mincostTicketsHelper(costs, uset, nthDay + 30, finalDay),
                mincostTicketsHelper(costs, uset, nthDay + 1, finalDay));
    }
    return min(a, min(b, c));
}

int mincostTickets(vector<int> &days, vector<int> &costs) {
    unordered_set<int> uset;
    int n = days.size();
    int finalDay = days[n - 1];
    for (int i = 0; i < n; i++) uset.insert(days[i]);
    return mincostTicketsHelper(costs, uset, 0, finalDay);
}

int main() {
    vector<int> days{1, 4, 6, 7, 8, 20};
    vector<int> costs{2, 7, 15};
    cout << mincostTickets(days, costs) << "\n";
    return 0;
}
