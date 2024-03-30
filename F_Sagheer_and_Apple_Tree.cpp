#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int n, a[maxN], p[maxN], vis[maxN];
vector<int> to[maxN];
void dfs(int x, int op) {
    vis[x] = op;
    if (!vis[p[x]]) {
        dfs(p[x], -op);
    }
}
long long res;
signed main() {
    ios;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        to[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!to[i].size()) {
            vis[i] = 1;
            dfs(i, 1); // 1是叶子, -1 不是叶子（不考虑）
        }
    }
    int xorsum = 0, num1 = 0, num2 = 0;
    map<int, int> cnt1, cnt2;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            xorsum ^= a[i];
            cnt1[a[i]]++, num1++;
        } else {
            cnt2[a[i]]++, num2++;
        }
    }
    if (xorsum == 0) {
        for (auto [x, y] : cnt1) {
            res += y * cnt2[x];
        }
        res += 1ll * num1 * (num1 - 1) / 2 + 1ll * num2 * (num2 - 1) / 2;
    } else {
        for (auto [x, y] : cnt1) {
            res += 1ll * y * cnt2[xorsum ^ x];
        }
    }
    cout << res;
    return 0;
}