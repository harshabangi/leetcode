#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define io ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
typedef long long int ll;

int main() {
    io;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_set<int> uset;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            uset.insert(a[i]);
        }
        int unique = uset.size();

        if ((n - unique) % 2 == 0) cout << unique << "\n";
        else cout << unique - 1 << "\n";
    }
    return 0;
}