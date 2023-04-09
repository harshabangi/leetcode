//
// Created by Harsha Vardhan on 02/01/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print_2d_array(vector<vector<int> > &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << "\n";
    }
}

//int sub_array_sum_equal_k(vector<int> &nums, int k) {
//    int n = nums.size();
//    vector<vector<int> > tmp(n, vector<int>(n, 9));
//    for (int i = 0; i < n; i++) {
//        tmp[i][i] = nums[i];
//    }
//    for (int i = 1; i < n; i++) {
//        nums[i] += nums[i - 1];
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i < j) {
//                if (i == 0) {
//                    tmp[i][j] = nums[j];
//                } else {
//                    tmp[i][j] = nums[j] - nums[i - 1];
//                }
//            }
//        }
//    }
//    int result = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (tmp[i][j] == k) {
//                result++;
//            }
//        }
//    }
//    print_2d_array(tmp);
//    return result;
//}

int sub_array_sum_equal_k(vector<int> &nums, int k) {
    int count = 0;
    int current_sum = 0;
    unordered_map<int, int> umap;
    umap[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        current_sum += nums[i];
        int x = current_sum - k;
        if (umap.find(x) != umap.end()) {
            count += umap[x];
        }
        if (umap.find(current_sum) != umap.end()) {
            umap[current_sum]++;
        } else {
            umap[current_sum] = 1;
        }
    }
    return count;
}

int main() {
    vector<int> nums{-1, -1, 1};
    cout << sub_array_sum_equal_k(nums, 0) << "\n";
    return 0;
}
