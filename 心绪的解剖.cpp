#include <bits/stdc++.h>
using namespace std;
#define int ll
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define pr printf
#define sc scanf
#define mem(a, k) memset(a, k, sizeof(a))
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define per(i, a, b) for (ll i = (a); i >= (b); i--)
#define cf        \
    int _;        \
    cin >> _;     \
    while (_--) { \
        solve();  \
    }
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
const int inf = 0x7fffffff, maxN = 2e5 + 5;
const double eps = 1e-8;
int p[maxN];
signed main() {
    int sz = 0;
    p[0] = 0, p[1] = 1;
    for (sz = 2;; sz++) {
        if (p[sz - 1] + p[sz - 2] <= 1e9) {
            p[sz] = p[sz - 1] + p[sz - 2];
        } else
            break;
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        vector<int> res;
        cin >> x;
        for (int i = 0; i < 3; i++) {
            int pos = lower_bound(p, p + sz, x) - p;
            if (p[pos] == x) {
                res.push_back(p[pos]);
                x -= p[pos];
            } else {
                res.push_back(p[pos - 1]);
                x -= p[pos - 1];
            }
        }
        if (x == 0) {
            for (auto i : res)
                cout << i << " ";
        } else
            cout << -1;
        cout << "\n";
    }

    return 0;
}