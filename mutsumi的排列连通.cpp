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
int n, a[maxN], b[maxN];
void solve() {
    int res = 5;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if (n == 1) {
        cout << "-1\n";
        return;
    } else if (n == 2) {
        if (a[1] == b[2]) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
        return;
    }
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] == b[i]) {
            cout << "1\n";
            return;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        set<int> s;
        s.insert(a[i]), s.insert(b[i + 1]);
        res = min(res, (int)s.size());
    }
    for (int i = 1; i <= n - 1; i++) {
        set<int> s;
        s.insert(b[i]), s.insert(a[i + 1]);
        res = min(res, (int)s.size());
    }
    if (res == 5) {
        cout << 2 << "\n";
    } else {
        cout << res << "\n";
    }
}
signed main() {
    ios;
    cf;
    return 0;
}