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
int n, m, sum[3005][3005], res;
char c[3005][3005];
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            sum[i][j] = sum[i][j - 1] + (c[i][j] == '*');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '.')
                continue;
            for (int k = 1; k + i <= n; k++) {
                if (j - k < 1 || c[i + k][j - k] == '.' || j + k > m || c[i + k][j + k] == '.')
                    break;
                if (sum[i + k][j + k] - sum[i + k][j - k - 1] == k * 2 + 1) {
                    res++;
                }
            }
        }
    }
    cout << res;
    return 0;
}