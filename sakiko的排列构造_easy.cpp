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
const int inf = 0x7fffffff, maxN = 2e6 + 5;
const double eps = 1e-8;
int n, a[maxN], ok, minp[maxN];
vector<int> primes;
void dfs(int pos, int x) {
    // cerr << pos << "\n";
    if (ok)
        return;
    if (pos == x + 1) {
        ok = 1;
        rep(i, 1, x) cout << a[i] << " \n"[i == x];
        return;
    }
    for (int i = x; i >= pos; i--) {
        if (minp[i + pos] == i + pos) {
            for (int j = pos, k = i; j <= i; j++, k--)
                a[j] = k;
            dfs(i + 1, x);
        }
    }
}
void solve(int x) {
    if (x == 1) {
        cout << "1\n";
        return;
    }
    ok = 0;
    if (x % 2 == 1) {
        a[1] = 1;
        dfs(2, x);
    } else
        dfs(1, x);
    if (!ok) {
        cout << "-1\n";
    }
}
void init() {
    for (int i = 2; i <= 2000000; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > 2000000)
                break;
            minp[i * p] = p;
            if (minp[i] == p)
                break;
        }
    }
}
signed main() {
    ios;
    init();
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = n; i >= 1; i--) {
            if (minp[i + 1] == i + 1 && (minp[i + 1 + n] == i + 1 + n || i == n)) {
                for (int j = 1; j <= i; j++) {
                    cout << i - j + 1 << " ";
                }
                for (int j = i + 1, x = n; j <= n; j++, x--) {
                    cout << x << " ";
                }
                return 0;
            }
        }
    } else {
        for (int i = n; i >= 2; i--) {
            if (minp[i + 2] == i + 2 && (minp[i + 1 + n] == i + 1 + n || i == n)) {
                cout << 1 << " ";
                for (int j = 2, x = i; j <= i; j++, x--) {
                    cout << x << " ";
                }
                for (int j = i + 1, x = n; j <= n; j++, x--) {
                    cout << x << " ";
                }
                return 0;
            }
        }
    }
    if (n == 1)
        return cout << 1, 0;
    return 0;
}