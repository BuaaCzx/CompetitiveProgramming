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
int n, a[maxN], sum, res, summ;
signed main() {
    ios;
    cin >> n;
    if (n == 1) {
        return cout << 1, 0;
    }
    rep(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    summ = sum;
    set<int> s;
    s.insert(1), s.insert(sum);
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            s.insert(i);
            s.insert(sum / i);
        }
    }
    s.insert(sum);
    for (auto it : s) {
        // cerr << it << "\n";
        if (it * n <= summ) {
            res++;
        }
    }
    cout << res;
    return 0;
}