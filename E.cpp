#include <bits/stdc++.h>
using namespace std;
#define int ll
#define mi(x, y) (((x) < (y)) ? (x) : (y))
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
int n, m, d[21][21], res, deg[21], op[21], poi = 0x7fffffff;
void dfs(int num, int res) {
    bool ok = 1;
    if (num > n) {
        poi = mi(poi, res);
        return;
    }
    if (op[num]) {
        dfs(num + 1, res);
        return;
    }
    op[num] = 1;
    for (int i = 1; i <= n; i++) {
        if (op[i] == 0) {
            op[i] = 1;
            dfs(num + 1, res + d[i][num]);
            op[i] = 0;
        }
    }
    op[num] = 0;
    return;
}
signed main() {
    ios;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = inf;
        }
        d[i][i] = 0;
    }
    //    cerr << d[1][3] << endl;
    for (int i = 0, x, y, w; i < m; i++) {
        cin >> x >> y >> w;
        res += w;
        d[x][y] = d[y][x] = mi(d[x][y], w);
        deg[x]++, deg[y]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                d[j][k] = mi(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] && d[1][i] == inf) {
            cout << "-1";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] & 1) {
            op[i] = 0;
            poi++;
        } else {
            op[i] = 2;
        }
    }
    dfs(1, 0);
    cout << res + poi;
    //    cerr << d[1][3];
    return 0;
}