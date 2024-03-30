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
const int maxN = 5005;
const ll inf = 1e18;
const double eps = 1e-8;
int n, m, k, a[maxN], b[maxN];
long long cost[maxN];
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cost[i] = inf;
    cost[k] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (cost[(j + k * a[i] - 1) % n + 1] <= cost[j] + b[i] * k) {
                    break;
                } else
                    cost[(j + k * a[i] - 1) % n + 1] = cost[j] + b[i] * k;
            }
        }
    }
    if (cost[n] == inf)
        cost[n] = -1;
    cout << cost[n] << "\n";
}
int main() {
    ios;
    cf;
    return 0;
}