//
// Created by Harsha Vardhan on 09/01/22.
//

#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int> &arr, int p, int q) {
    while (p < q) {
        int tmp = arr[p];
        arr[p] = arr[q];
        arr[q] = tmp;
        p++;
        q--;
    }
}

void rotate_array(vector<int> &arr, int k) {
    int size = arr.size();
    int i = 0, j = size - 1;
    reverse_array(arr, i, j);
    reverse_array(arr, 0, k - 1);
    reverse_array(arr, k, j);
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    rotate_array(arr, 3);
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}