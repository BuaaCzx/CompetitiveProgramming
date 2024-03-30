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
int n, m;
vector<int> nxt[maxN];
int vis[maxN];
bool dfs(int x, int op) {
    vis[x] = op;
    for (auto y : nxt[x]) {
        if (vis[y] == op)
            return false;
        if (vis[y] == -1 && !dfs(y, op ^ 1)) {
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vis[i] = -1;
    }
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        nxt[u].pb(v);
        nxt[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            if (!dfs(i, 0)) {
                cout << -1;
                return;
            }
        }
    }
    int res[2] = {0, 0};
    vector<int> ans[2];
    for (int i = 1; i <= n; i++) {
        res[vis[i]]++, ans[vis[i]].push_back(i);
    }
    for (int i = 0; i < 2; i++) {
        cout << res[i] << "\n";
        for (auto x : ans[i])
            cout << x << " ";
        cout << "\n";
    }
}
int main() {
    ios;
    solve();
    return 0;
}