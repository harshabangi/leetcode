//
// Created by Harsha Vardhan on 19/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool maximumEvenSplitHelper(vector<long long> &tmp, int idx, long long finalSumDup, long long finalSum) {
    if (finalSumDup == 0) {
        return true;
    }
    if (finalSumDup < 0 || finalSumDup < idx) return false;
    for (int i = idx; i < finalSum; i += 2) {
        cout << i << "\n";
        tmp.push_back(i);
        if (maximumEvenSplitHelper(tmp, i + 2, finalSumDup - i, finalSum)) return true;
        tmp.pop_back();
    }
    return false;
}

vector<long long> maximumEvenSplit(long long finalSum) {
    vector<long long> tmp;
    if (finalSum % 2 != 0) return tmp;
    if (finalSum == 2 || finalSum == 4) {
        tmp.push_back(finalSum);
        return tmp;
    }
    maximumEvenSplitHelper(tmp, 2, finalSum, finalSum);
    return tmp;
}

int main() {
    vector<long long> ans = maximumEvenSplit(28);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
