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
}
int main() {
    int n, k, a, b, x;
    long long res = 0;
    cin >> n >> k >> a >> b;
    x = n;
    if (k == 1) {
        cout << 1ll * a * (n - 1) << "\n";
        return 0;
    }
    while (x != 1) {
        if (x < k) {
            res += 1ll * a * (x - 1);
            x -= x - 1;

        } else if (x % k || k == 1) {
            res += 1ll * a * (x % k);
            x -= x % k;
        } else {
            if (1ll * a * (x - x / k) <= b) {
                res += 1ll * a * (x - x / k);
            } else {
                res += b;
            }
            x /= k;
        }
    }
    cout << res;
    return 0;
}