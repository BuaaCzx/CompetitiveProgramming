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
void solve() {
    int n, x, minn = inf;
    cin >> x >> n;
    for (int i = 1; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
            int p1 = x % i;
            if (x / i >= n) {
                minn = min(minn, x / i);
            }
            if (i >= n) {
                minn = min(minn, i);
            }
        }
    }
    cout << x / minn << "\n";
}
int main() {
    ios;
    cf;
    return 0;
}