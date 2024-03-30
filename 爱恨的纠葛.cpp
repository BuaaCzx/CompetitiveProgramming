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
int a[maxN], b[maxN];
signed main() {
    ios;
    int n, res = inf, pa, pb;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        int p = lower_bound(a + 1, a + n + 1, b[i]) - a;
        if (p != n + 1 && abs(b[i] - a[p]) < res) {
            res = abs(b[i] - a[p]);
            pa = p, pb = i;
        }
        if (p != 1 && abs(b[i] - a[p - 1]) < res) {
            res =
                abs(b[i] - a[p - 1]);
            pa = p - 1, pb = i;
        }
    }
    swap(a[pa], a[pb]);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}