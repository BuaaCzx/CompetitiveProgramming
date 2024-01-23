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
const int inf = 0x7fffffff, maxN = 1e6 + 5;
const double eps = 1e-8;
void solve() {
}
int n, a[maxN], res;
int main() {
    ios;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int p = 1;
    while (p < n) {
        p += a[p], res++;
    }
    cout << (p == n ? "Yes" : "No") << '\n';
    cout << res;
    return 0;
}