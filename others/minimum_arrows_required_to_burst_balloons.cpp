//
// Created by Harsha Vardhan on 27/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> &arr, int val, int idx) {
    if (idx >= arr.size()) return;
    if (arr[idx] != -1 && (val - arr[idx]) == 1) {
        int t = arr[idx];
        arr[idx] = -1;
        helper(arr, t, idx + 1);
    } else {
        helper(arr, val, idx + 1);
    }
}

int solve(vector<int> &arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != -1) {
            helper(arr, arr[i], i + 1);
            ans += 1;
        }
    }
    return ans;
}

#include <unordered_map>

int burstingBalloons(int *arr, int n)
{

    unordered_map<int, int> arrowsAtHeight;
    for (int i = 0; i < n; i++)
    {
        if (arrowsAtHeight.find(arr[i]) != arrowsAtHeight.end())
        {
            // Destroying Ballon So Frequency will decrease.
            arrowsAtHeight[arr[i]]--;
            if (arrowsAtHeight[arr[i]] == 0)
            {
                arrowsAtHeight.erase(arr[i]);
            }
        }

        // Frequency of Arrow at 1 less height will increase.
        arrowsAtHeight[arr[i] - 1]++;
    }

    int ans = 0;
    for (auto arrow : arrowsAtHeight)
    {
        ans += arrow.second;
    }

    return ans;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    cout << solve1(arr) << "\n";
    return 0;
}
