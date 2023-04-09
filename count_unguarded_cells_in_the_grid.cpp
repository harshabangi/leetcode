//
// Created by Harsha Vardhan on 10/06/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void exploreLeft(int x, int y, vector<vector<char>> &grid) {
    while (y >= 0 && grid[x][y] != 'W' && grid[x][y] != 'G') {
        grid[x][y] = 'X';
        y--;
    }
}

void exploreRight(int x, int y, vector<vector<char>> &grid, int n) {
    while (y < n && grid[x][y] != 'W' && grid[x][y] != 'G') {
        grid[x][y] = 'X';
        y++;
    }
}

void exploreTop(int x, int y, vector<vector<char>> &grid) {
    while (x >= 0 && grid[x][y] != 'W' && grid[x][y] != 'G') {
        grid[x][y] = 'X';
        x--;
    }
}

void exploreBottom(int x, int y, vector<vector<char>> &grid, int m) {
    while (x < m && grid[x][y] != 'W' && grid[x][y] != 'G') {
        grid[x][y] = 'X';
        x++;
    }
}

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
    vector<vector<char>> grid(m, vector<char>(n, 'E'));

    for (int i = 0; i < guards.size(); i++) {
        grid[guards[i][0]][guards[i][1]] = 'G';
    }
    for (int i = 0; i < walls.size(); i++) {
        grid[walls[i][0]][walls[i][1]] = 'W';
    }

    for (int i = 0; i < guards.size(); i++) {
        int x = guards[i][0], y = guards[i][1];
        exploreLeft(x, y, grid);
        exploreRight(x, y, grid, n);
        exploreTop(x, y, grid);
        exploreBottom(x, y, grid, m);
    }

    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 'E') {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
