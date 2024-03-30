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
int n, res = inf, len;
char s[55][55];
bool eq(char *s1, char *s2, int st) {
    for (int i = 0; i < len; i++, st++) {
        if (s1[i] != s2[st % len]) {
            return 0;
        }
    }
    return 1;
}
int calc(int id) {
    int res = 0;
    rep(i, 0, n - 1) {
        bool fl = 0;
        rep(j, 0, len - 1) {
            if (eq(s[id], s[i], j)) {
                res += j;
                fl = 1;
                break;
            }
        }
        if (!fl) {
            return -1;
        }
    }
    return res;
}
int main() {
    scanf("%d", &n);
    rep(i, 0, n - 1) {
        scanf("%s", &s[i]);
    }
    len = strlen(s[0]);
    rep(i, 0, n - 1) {
        res = min(res, calc(i));
    }
    cout << res;
    return 0;
}