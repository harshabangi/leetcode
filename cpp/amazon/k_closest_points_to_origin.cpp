//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Point {
    int x;
    int y;
    int distanceToOrigin;

    Point(int x, int y) : x(x), y(y), distanceToOrigin(0) {};
};

struct comparator {
    bool operator()(Point a, Point b) {
        return a.distanceToOrigin > b.distanceToOrigin;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<Point, vector<Point>, comparator> pq;
    for (int i = 0; i < points.size(); i++) {
        Point p = Point(points[i][0], points[i][1]);
        p.distanceToOrigin = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        pq.push(p);
    }
    vector<vector<int>> ans;
    while (k--) {
        Point p = pq.top();
        vector<int> temp(2);
        temp[0] = p.x;
        temp[1] = p.y;
        ans.push_back(temp);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<vector<int>> points = {
            {3,  3},
            {5,  -1},
            {-2, 4}
    };
    kClosest(points, 2);
    return 0;
}
