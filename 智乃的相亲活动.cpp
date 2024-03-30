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
const int inf = 0x7fffffff, maxN = 2e5 + 5, mod = 1e9 + 7;
const double eps = 1e-8;
int ksm(int a, int b) {
    int res = 1, base = a;
    while (b) {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}
int inv(int x) {
    return ksm(x, mod - 2);
}
vector<int> a[maxN], b[maxN];
int resa[maxN], resb[maxN];
signed main() {
    cout << "modint\n";
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1, u, v; i <= k; i++) {
        cin >> u >> v;
        a[u].pb(v);
        b[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        resa[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        resb[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (auto j : b[i]) {
            (resa[j] *= (b[i].size() - 1) * inv(b[i].size()) % mod) %= mod;
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        (res += (1 - resa[i] + mod) % mod) %= mod;
    }
    cout << res << " ";
    for (int i = 1; i <= n; i++) {
        for (auto j : a[i]) {
            (resb[j] *= (a[i].size() - 1) * inv(a[i].size()) % mod) %= mod;
        }
    }
    res = 0;
    for (int i = 1; i <= m; i++) {
        (res += (1 - resb[i] + mod) % mod) %= mod;
    }
    cout << res << " ";
    return 0;
}