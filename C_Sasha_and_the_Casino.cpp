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
int f(int a, int b) {
    return a % b == 0 ? a / b : a / b + 1;
}
void solve() {
    int k, x, a;
    cin >> k >> x >> a;
    int sum = 1, cost = 1;
    for (int i = 2; i <= x; i++) {
        cost = sum / (k - 1) + 1;
        sum += cost;
        if (sum >= a) {
            cout << "NO\n";
            return;
        }
    }
    //    cerr << sum << "\n";
    if ((a - sum) * (k) > a) {
        cout << "YES" << endl;
    } else {
        cout << "NO\n";
    }
}
signed main() {
    ios;
    cf;
    return 0;
}