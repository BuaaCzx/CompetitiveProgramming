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
int A, B, C, D, E, F, G, P, X1, X2, Y1, Y2, res = -inf;
long long f(ll x, ll y) {
    return (A * x * x * x % P + B * y * y * y % P + C * x * x * y % P + D * x * y * y % P + E * x * y % P + F * x % P + G * y % P) % P;
}
int main() {

    cin >> A >> B >> C >> D >> E >> F >> G >> P >> X1 >> X2 >> Y1 >> Y2;
    for (int x = X1; x <= X2; x++) {
        for (int y = Y1; y <= Y2; y++) {
            res = max(res, (int)f(x, y));
        }
    }
    cout << res;
    return 0;
}