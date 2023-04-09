#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define io ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
typedef long long ll;

int main() {
    io;
    int t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        unordered_map<ll, ll> umap;

        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            umap[a[i]]++;
        }

        sort(a.begin(), a.end());

        for (ll i = 0; i < a.size(); i++) {
            if (umap.find(a[i]) != umap.end()) {
                if (umap.find(x * a[i]) != umap.end()) {
                    umap[x * a[i]]--;
                    umap[a[i]]--;
                    if (umap[x * a[i]] == 0) {
                        umap.erase(x * a[i]);
                    }
                    if (umap[a[i]] == 0) {
                        umap.erase(a[i]);
                    }
                }
            }
        }

        ll ans = 0;
        for (auto it: umap) {
            ans += it.second;
        }
        cout << ans << "\n";
    }
    return 0;
}