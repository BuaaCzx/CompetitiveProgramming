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
int n, a[maxN], res;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i]--;
    a[0] = a[n + 1] = inf;
    for (int i = 1; i <= n + 1; i++) {
        int x = min(a[i], a[i - 1]);
        a[i] -= x;
        res += x;
    }
    cout << res;
    return 0;
}
