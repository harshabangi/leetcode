//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

pair<int, int> moviesOnFlight(vector<int> nums, int d) {
    d = d - 30;
    vector<pair<int, int>> movies(nums.size());
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
        movies[i] = {nums[i], i};
    }
    sort(movies.begin(), movies.end());
    int i = 0, j = movies.size() - 1;
    int sum_mx = INT_MIN, mx = INT_MIN;
    int p, q;
    while (i < j) {
        int curr = movies[i].first + movies[j].first;
        if (curr <= d) {
            if (curr == sum_mx) {
                int t = max(movies[i].first, movies[j].first);
                if (t > mx) {
                    p = movies[i].second;
                    q = movies[j].second;
                    mx = t;
                }
            }
            if (curr > sum_mx) {
                p = movies[i].second;
                q = movies[j].second;
                mx = max(movies[i].first, movies[j].first);
                sum_mx = curr;
            }
            i++;
        } else {
            j--;
        }
    }
    return make_pair(p, q);
}

int main() {
    vector<int> nums1{90, 85, 75, 60, 120, 150, 125};
    pair<int, int> t1 = moviesOnFlight(nums1, 250);
    cout << t1.first << ", " << t1.second << "\n";

    vector<int> nums2{90, 85, 75, 60, 155, 150, 125};
    pair<int, int> t2 = moviesOnFlight(nums2, 250);
    cout << t2.first << ", " << t2.second << "\n";

    vector<int> nums3{90, 85, 75, 60, 120, 110, 110, 150, 125};
    pair<int, int> t3 = moviesOnFlight(nums3, 250);
    cout << t3.first << ", " << t3.second << "\n";
    return 0;
}
