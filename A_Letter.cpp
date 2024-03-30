#include <bits/stdc++.h>
using namespace std;
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
void solve() {
}
char c[55][55];
int n, m, x[2], y[2];
int main() {
    ios;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == '*') {
                if (!x[0] || (i <= x[0]))
                    x[0] = i;
                if (!y[0] || (j <= y[0]))
                    y[0] = j;
                if (!y[0] || (i >= x[1])) {
                    x[1] = i;
                }
                if (!y[1] || (j >= y[1])) {
                    y[1] = j;
                }
            }
        }
    }
    for (int i = x[0]; i <= x[1]; i++) {
        for (int j = y[0]; j <= y[1]; j++) {
            cout << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}