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
struct node {
    int l, r;
} sg[maxN];

int n, t;

int main() {
    ios;
    cin >> n >> t;
    t *= 2;
    for (int i = 0, a, x; i < n; i++) {
        cin >> x >> a;
        x *= 2;
        sg[i] = {x - a, x + a};
    }
    sort(sg, sg + n, [](node x, node y) {
        return x.l < y.l;
    });
    int res = 2;
    for (int i = 1; i < n; i++) {
        //    cout << sg[i].l << " " << sg[i].r << endl;
        if (sg[i].l - sg[i - 1].r > t) {
            res += 2;
        } else if (sg[i].l - sg[i - 1].r == t) {
            res++;
        }
    }
    cout << res;
    return 0;
}