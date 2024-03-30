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
int n, m, x, y;
char c[205][205];
int op[105], z[105];
signed main() {
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    int p, q;
    cin >> p >> q;
    for (int i = 0; i < q; i++) {
        cin >> op[i] >> z[i];
    }
    while (p--) {
        for (int j = 0; j < q; j++) {
            if (op[j] == 1) {
                char tmp = c[z[j]][m];
                for (int i = m; i >= 2; i--) {
                    c[z[j]][i] = c[z[j]][i - 1];
                }
                c[z[j]][1] = tmp;
            } else {
                char tmp = c[n][z[j]];
                for (int i = n; i >= 2; i--) {
                    c[i][z[j]] = c[i - 1][z[j]];
                }
                c[1][z[j]] = tmp;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout << c[i][j];
        //     }
        //     cout << "\n";
        // }
    }

    cout << c[x][y];
    return 0;
}