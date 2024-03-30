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
int n, k, a[maxN];
signed main() {
    ios;
    cin >> n >> k;
    set<int> s;
    int sum = 0, res = 0;
    s.insert(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        (sum += a[i]) %= k;
        if (s.count(sum)) {
            res++, s.clear();
            s.insert(0);
            sum = 0;
        } else {
            s.insert(sum);
        }
    }
    cout << res;
    return 0;
}