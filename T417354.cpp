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
char s[2005];
int res;
int main() {
    sc("%s", s);
    char *p = s;
    while (strstr(p, "Genshin") != NULL) {
        p = strstr(p, "Genshin") + 7;
        char *q = p;
        while (strstr(q, "player") != NULL) {
            res++, q = strstr(q, "player") + 6;
        }
    }
    cout << res;
    return 0;
}