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
void solve() {
}
int n, p, m;
__int128_t d[maxN], t[maxN], sum;
ll res;

signed main() {
    ios;
    cin >> n >> p >> m;
    d[0] = 1, d[n + 1] = m + 1;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        d[i] = a, t[i] = b;
    }
    int st, ed;
    st = d[1] == 1 ? 1 : 0;
    for (int i = st; i <= n; i++) {
        sum += t[i];
        res += sum >= 0 ? max((__int128_t)0, d[i + 1] - d[i] - sum / p) : d[i + 1] - d[i];
        sum -= (d[i + 1] - d[i]) * p;
    }
    cout << res;
    return 0;
}