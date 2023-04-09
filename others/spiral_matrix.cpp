//
// Created by Harsha Vardhan on 13/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool underBoundary(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    char facing = 'W';
    int c = 0, m = matrix.size(), n = matrix[0].size();
    int i = 0, j = 0;
    while (true) {
        if (c == m * n) break;
        if (facing == 'W') {
            if (underBoundary(i, j, m, n) && matrix[i][j] != INT_MIN) {
                ans.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                c++;
                j++;
            } else {
                i++;
                j--;
                facing = 'S';
            }
        } else if (facing == 'S') {
            if (underBoundary(i, j, m, n) && matrix[i][j] != INT_MIN) {
                ans.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                c++;
                i++;
            } else {
                facing = 'E';
                i--;
                j--;
            }
        } else if (facing == 'E') {
            if (underBoundary(i, j, m, n) && matrix[i][j] != INT_MIN) {
                ans.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                c++;
                j--;
            } else {
                facing = 'N';
                i--;
                j++;
            }
        } else {
            if (underBoundary(i, j, m, n) && matrix[i][j] != INT_MIN) {
                ans.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                c++;
                i--;
            } else {
                facing = 'W';
                i++;
                j++;
            }
        }
    }
    return ans;
}


void print_matrix_in_spiral_form(vector<vector<int>> &inp) {
    int i = 0, j = 0, c = 0;
    int m = inp.size(), n = inp[0].size();
    char facing = 'W';

    while (true) {
        if (c == m * n) break;
        if (facing == 'W') {
            if (underBoundary(i, j, m, n) && inp[i][j] != INT_MIN) {
                cout << inp[i][j] << " ";
                inp[i][j] = INT_MIN;
                c++;
                j++;
            } else {
                facing = 'S';
                i++;
                j--;
            }
        } else if (facing == 'S') {
            if (underBoundary(i, j, m, n) && inp[i][j] != INT_MIN) {
                cout << inp[i][j] << " ";
                inp[i][j] = INT_MIN;
                c++;
                i++;
            } else {
                facing = 'E';
                i--;
                j--;
            }
        } else if (facing == 'E') {
            if (underBoundary(i, j, m, n) && inp[i][j] != INT_MIN) {
                cout << inp[i][j] << " ";
                inp[i][j] = INT_MIN;
                c++;
                j--;
            } else {
                facing = 'N';
                i--;
                j++;
            }
        } else {
            if (underBoundary(i, j, m, n) && inp[i][j] != INT_MIN) {
                cout << inp[i][j] << " ";
                inp[i][j] = INT_MIN;
                c++;
                i--;
            } else {
                facing = 'W';
                i++;
                j++;
            }
        }
    }
}

int main() {
    vector<vector<int>> inp{
            {2, 5},
            {8, 5},
            {0, -1}
    };
    print_matrix_in_spiral_form(inp);
    return 0;
}
