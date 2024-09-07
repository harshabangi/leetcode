//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> getIndexesOfTheSongs(vector<int> songDurations, int rideDuration) {
    unordered_map<int, int> umap;
    for (int i = 0; i < songDurations.size(); i++) {
        umap[songDurations[i]] = i;
    }
    sort(songDurations.begin(), songDurations.end());
    int i = 0, j = songDurations.size() - 1;
    int expected = rideDuration - 30;
    vector<vector<int>> ans;
    while (i < j) {
        if (songDurations[i] + songDurations[j] == expected) {
            i++;
            j--;
            vector<int> temp(2);
            temp[0] = umap[songDurations[i]];
            temp[1] = umap[songDurations[j]];
            ans.push_back(temp);
        } else if (songDurations[i] + songDurations[j] < expected) {
            i++;
        } else {
            j--;
        }
    }
    return ans;
}

int main() {
    vector<int> songDurations{100, 180, 40, 120, 10};
    int rideDuration = 250;
    vector<vector<int>> ans = getIndexesOfTheSongs(songDurations, rideDuration);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ", " << ans[i][1] << "\n";
    }
    return 0;
}
