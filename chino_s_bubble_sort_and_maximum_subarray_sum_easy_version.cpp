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
int n, k, a[maxN];
long long calc() {
    long long res = a[1], cur = a[1];
    for (int i = 2; i <= n; i++) {
        if (cur < 0) {
            cur = a[i];
        } else {
            cur += a[i];
        }
        res = max(res, cur);
    }
    return res;
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (k == 0) {
        cout << calc() << '\n';
    } else {
        long long res = -1e18;
        for (int i = 1; i < n; i++) {
            swap(a[i], a[i + 1]);
            res = max(res, calc());
            swap(a[i], a[i + 1]);
        }
        cout << res << '\n';
    }
    return 0;
}