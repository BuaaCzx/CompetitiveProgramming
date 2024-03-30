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
const int inf = 0x7fffffff, N = 2e5 + 5;
const double eps = 1e-8;
int n, a[N];
int d[N];
void solve() {
    int add = 0;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) d[i] = a[i] - a[i - 1];
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    if (n % 2 == 0) {
        cout << "YES\n";
        return;
    } else {
        for (int i = n - 1; i >= 1; i -= 2) {
            d[i + 1] += add, d[i] += add;
            int cnt = max(d[i + 1] / i, 0ll);
            d[i + 1] -= cnt * i, d[i] += cnt;
            if (d[i + 1] < 0 || d[i] < 0) {
                cout << "NO\n";
                return;
            }
            add += cnt;
        }
    }
    cout << "YES\n";
    return;
}
signed main() {
    ios;
    cf;
    return 0;
}