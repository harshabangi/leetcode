//
// Created by Harsha Vardhan on 03/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> dirx{-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> diry{0, 1, 1, 1, 0, -1, -1, -1};


bool underBoundary(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

bool search2DHelper(vector<vector<char>> grid, string &word, int i, int j, int idx) {
    if (idx == word.size()) return true;
    if (!underBoundary(i, j, grid.size(), grid[0].size()) || grid[i][j] == '*' || word[idx] != grid[i][j]) return false;
    bool ans = false;
    cout << i << ", " << j << ", " << idx << "\n";
    char tmp = grid[i][j];
    grid[i][j] = '*';
    for (int l = 0; l < dirx.size(); l++) {
        if (search2DHelper(grid, word, i + dirx[l], j + diry[l], idx + 1)) return true;
    }
    grid[i][j] = tmp;
    return ans;
}

vector<vector<int>> search2D(vector<vector<char>> &grid, string &word) {
    vector<vector<int>> ans;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == word[0]) {
                if (search2DHelper(grid, word, i, j, 0)) {
                    vector<int> tmp;
                    tmp[0] = i;
                    tmp[1] = j;
                    ans.push_back(tmp);
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<char>> grid = {
            {'G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S'},
            {'G', 'E', 'E', 'K', 'S', 'Q', 'U', 'I', 'Z', 'G', 'E', 'E', 'K'},
            {'I', 'D', 'E', 'Q', 'A', 'P', 'R', 'A', 'C', 'T', 'I', 'C', 'E'}
    };
    string word = "GEEKS";
    vector<vector<int>> ans = search2D(grid, word);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ", " << ans[i][1] << "\n";
    }
    return 0;
}
