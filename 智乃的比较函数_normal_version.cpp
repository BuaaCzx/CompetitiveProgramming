#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define pr printf
#define sc scanf
#define pii pair<int, int>
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
int n, u[maxN], v[maxN], x[maxN], a[5];
bool check() {
    for (int i = 1; i <= n; i++) {
        if (a[u[i]] < a[v[i]] != x[i])
            return 0;
    }
    return 1;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u[i] >> v[i] >> x[i];
    }
    for (a[1] = 1; a[1] <= 3; a[1]++) {
        for (a[2] = 1; a[2] <= 3; a[2]++) {
            for (a[3] = 1; a[3] <= 3; a[3]++) {
                if (check()) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
    return;
}
int main() {
    ios;
    cf;
    return 0;
}