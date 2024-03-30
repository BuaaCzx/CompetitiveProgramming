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
int res[maxN];
int main() {
    int m, n, cnt = 0;
    string s;
    long long d;
    cin >> m >> n;
    cin >> s >> d;
    int x = m;
    while (d) {
        res[cnt++] = d % (s[--m] - '0');
        d /= s[m] - '0';
    }
    per(i, x - 1, 0) cout << res[i];
    return 0;
}