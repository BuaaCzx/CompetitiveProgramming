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
int n, m, k, a[305][305], res;
int main() {
    cin >> n >> m >> k;
    for (int i = 1, x, y; i <= k; i++) {
        cin >> x >> y;
        a[x][y] = 1;
        res += 4 - a[x + 1][y] - a[x][y + 1] - a[x][y - 1] - a[x - 1][y];
    }
    cout << res;
    return 0;
}