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
int n, type[maxN], ok = 1, num[maxN];
vector<int> to[maxN], son[maxN];
vector<int> dfs(int x) {
    if (!ok)
        return vector<int>();
    vector<int> res;
    if (to[x].empty()) {
        if (type[x] == 1) {
            ok = 0;
            return res;
        } else {
            res.pb(x);
            return res;
        }
    }
    for (auto nxt : to[x]) {
        vector<int> t = dfs(nxt);
        res.insert(res.end(), t.begin(), t.end());
    }
    if (type[x] == 0) {
        res.pb(x);
        return res;
    } else {
        res.pb(x);
        if (res.size() < 2) {
            ok = 0;
            return vector<int>();
        } else {
            int sz = res.size();
            if (sz % 2 == 0) {
                int cur = 1;
                for (auto i : res) {
                    num[i] = cur;
                    cur = cur == 1 ? 2 : 1;
                }
            } else {
                for (int i = 3, cur = 1; i < sz; i++) {
                    num[res[i]] = cur;
                    cur = cur == 1 ? 2 : 1;
                }
                num[res[0]] = num[res[1]] = num[res[2]] = 1;
            }
            return vector<int>();
        }
    }
}
signed main() {
    ios;
    cin >> n;
    char c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        type[i] = c == 'R' ? 1 : 0;
    }
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        to[x].pb(i);
    }
    dfs(1);
    if (ok)
        for (int i = 1; i <= n; i++) {
            cout << (num[i] ? num[i] : 1);
        }
    else {
        cout << "-1";
    }
    return 0;
}