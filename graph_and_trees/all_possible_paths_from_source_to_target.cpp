//
// Created by Harsha Vardhan on 03/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void allPathsSourceTargetHelper(vector<vector<int> > &graph, int k, vector<int> path, vector<vector<int> > &ans) {
    path.push_back(k);
    for (int i = 0; i < graph[k].size(); i++) {
        allPathsSourceTargetHelper(graph, graph[k][i], path, ans);
    }
    if (k == graph.size() - 1) ans.push_back(path);
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int> > &graph) {
    vector<int> initialPath;
    //initialPath.push_back(0);
    vector<vector<int>> ans;
    allPathsSourceTargetHelper(graph, 0, initialPath, ans);
    return ans;
}

int main() {
    vector<vector<int> > graph = {{4, 3, 1},
                                  {3, 2, 4},
                                  {3},
                                  {4}, {}};
    vector<vector<int>> ans = allPathsSourceTarget(graph);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
