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
vector<int> primes;
int minp[maxN], ok[maxN];
void init() {
    for (int i = 2; i <= 100; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.pb(i);
        }
        for (auto p : primes) {
            if (1ll * p * i > 100)
                break;
            minp[p * i] = p;
            if (i % p == 0)
                break;
        }
    }
    for (auto p1 : primes) {
        for (auto p2 : primes) {
            for (auto p3 : primes) {
                if (p1 != p2 && p1 != p3 && p2 != p3 && p1 * p2 * p3 < 100) {
                    ok[p1 * p2 * p3] = 1;
                }
            }
        }
    }
}
signed main() {
    init();
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (ok[i]) {
            return cout << i, 0;
        }
    }
    cout << -1;
    return 0;
}