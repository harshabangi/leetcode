#include <iostream>
#include <vector>
#include <algorithm>

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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int i = 0;
        while (a[i] == 0) {
            i++;
        }
        unsigned long long ans = 0;
        for (int k = i; k < n - 1; k++) {
            if (a[k] != 0) ans += a[k];
            else ans += 1;
        }
        cout << ans << "\n";
    }
    return 0;
}