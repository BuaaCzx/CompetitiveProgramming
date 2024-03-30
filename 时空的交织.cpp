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
int n, m, a[maxN], b[maxN];
int max(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}
signed main() {
    ios;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int maxa = a[1], maxb = b[1], cura = a[1], curb = b[1];
    for (int i = 2; i <= n; i++) {
        if (cura < 0) {
            cura = 0;
        }
        cura += a[i];
        maxa = max(maxa, cura);
    }
    for (int i = 2; i <= m; i++) {
        if (curb < 0) {
            curb = 0;
        }
        curb += b[i];
        maxb = max(maxb, curb);
    }
    int mina = a[1], minb = b[1];
    cura = a[1], curb = b[1];
    for (int i = 2; i <= n; i++) {
        if (cura > 0) {
            cura = 0;
        }
        cura += a[i];
        mina = min(mina, cura);
    }
    for (int i = 2; i <= m; i++) {
        if (curb > 0) {
            curb = 0;
        }
        curb += b[i];
        minb = min(minb, curb);
    }
    cout << max(maxa * maxb, mina * minb, maxa * minb, mina * maxb);
    return 0;
}