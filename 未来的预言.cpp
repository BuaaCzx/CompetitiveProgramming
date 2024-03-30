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
void solve() {
}
signed main() {
    char c;
    int x;
    cin >> c >> c >> x;
    string s;
    cin >> s;
    int r = 0, p = 0, cnt = 0;
    for (auto c : s) {
        cnt++;
        if (c == 'R')
            r++;
        else
            p++;
        if (r > x / 2) {
            return cout << "kou!\n"
                        << cnt,
                   0;
        }
        if (p > x / 2) {
            return cout << "yukari!\n"
                        << cnt,
                   0;
        }
    }
    cout << "to be continued.\n"
         << cnt;
    return 0;
}