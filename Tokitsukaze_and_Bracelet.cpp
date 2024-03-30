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
    int n;
    cin >> n;
    while (n--) {
        int a, b, c, res = 0;
        cin >> a >> b >> c;
        res += a == 100 ? 0 : (a == 150 ? 1 : 2);
        res += b <= 32 ? 0 : b <= 40 ? 1
                                     : 2;
        res += c <= 32 ? 0 : c <= 40 ? 1
                                     : 2;
        cout << res << "\n";
    }
    return 0;
}