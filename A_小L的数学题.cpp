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
const int inf = 0x7fffffff, mod = 998244353, maxN = 1e7 + 5;
const double eps = 1e-8;
int minp[maxN], f[maxN];
vector<int> primes;
long long solve(long long x) {
    int res = 0;
    while (x > 1) {
        res++;
        int p = minp[x];
        while (x % p == 0) {
            x /= p;
        }
    }
    return res;
}
int main() {
    long long n;
    cin >> n;
    for (int i = 2; i <= 1e7; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.pb(i);
        }
        for (auto p : primes) {
            if (1ll * p * i > 1e7)
                break;
            minp[p * i] = p;
            if (minp[i] == p)
                break;
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        (res += 1ll << solve(i)) %= mod;
    }
    cout << res;
    return 0;
}
