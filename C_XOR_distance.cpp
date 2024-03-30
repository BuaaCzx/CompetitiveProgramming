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
    ll a, b, r;
    cin >> a >> b >> r;
    if (a < b) {
        swap(a, b);
    }
    bool fl = 0;
    long long x = 0;
    for (int i = 62; i >= 0; i--) {
        int weia = (a >> i) & 1, weib = (b >> i) & 1;
        if (weia == 1 && weib == 0) {
            if (!fl)
                fl = 1;
            else {
                if ((x | (1ll << i)) <= r) {
                    x |= (1ll << i);
                }
            }
        }
    }
    cout << abs((x ^ a) - (x ^ b)) << endl;
}
int main() {
    ios;
    cf;
    return 0;
}