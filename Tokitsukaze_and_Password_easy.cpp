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
const int inf = 0x7fffffff, maxN = 2e5 + 5, mod = 1e9 + 7;
const double eps = 1e-8;
int n, num[301], a[11], vis[11];
long long res;
string s;
string y;
int getnum(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c == '_')
        return '_';
    return num[c - 'a'];
}
void debug() {
    // for (int i = 0; i < n; i++) {
    //     cerr << a[i];
    // }
    // cerr << endl;
}
void dfs(int id) {
    if (id == n) {
        int x = 0;
        for (int i = max(n - 4, 0); i < n; i++) {
            x = x * 10 + a[i];
        }
        if (x % 8 != 0)
            return;
        for (int i = 0; i < n; i++) {
            if (a[i] > y[i] - '0') {
                return;
            } else if (a[i] < y[i] - '0') {
                (res += 1) %= mod;
                debug();
                return;
            }
        }
        debug();
        (res += 1) %= mod;
        return;
    }
    if (s[id] == '_') {
        for (int i = id == 0 ? 1 : 0; i <= 9; i++) {
            a[id] = i;
            dfs(id + 1);
        }
    } else if (getnum(s[id]) == -1) {
        for (int i = id == 0 ? 1 : 0; i <= 9; i++) {
            if (vis[i])
                continue;
            vis[i] = 1;
            a[id] = i;
            num[s[id] - 'a'] = i;
            dfs(id + 1);
            vis[i] = 0;
            num[s[id] - 'a'] = -1;
        }
    } else if (getnum(s[id]) != -1) {
        a[id] = getnum(s[id]);
        dfs(id + 1);
    }
}
void solve() {
    res = 0;
    mem(vis, 0);
    cin >> n >> s >> y;
    if (n == 1) {
        if (s[0] >= '0' && s[0] <= '9') {
            int x = s[0] - '0';
            if (x % 8 != 0 || x > y[0] - '0') {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        } else {
            cout << (y[0] - '0') / 8 + 1 << "\n";
        }
        return;
    }
    if (s[0] == '0') {
        cout << "0\n";
        return;
    }
    for (auto c : s)
        if ((c < '0' || c > '9') && c != '_')
            num[c - 'a'] = -1;
    dfs(0);
    cout << res << "\n";
}
int main() {
    ios;
    cf;
    return 0;
}