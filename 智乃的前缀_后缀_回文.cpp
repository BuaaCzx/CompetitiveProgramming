#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int inf = 0x7fffffff, maxN = 2e5 + 5, mod1 = 1e9 + 7, mod2 = 998244353, base1 = 131, base2 = 233;
const double eps = 1e-8;
int n, m;
char s[maxN], t[maxN], tmp[maxN];
int s_hashp[3][maxN], ss_hashp[3][maxN], t_hashp[3][maxN], tt_hashp[3][maxN];
bool s_hwp[maxN], t_hwp[maxN];
int s_hashs[3][maxN], ss_hashs[3][maxN], t_hashs[3][maxN], tt_hashs[3][maxN];
bool s_hws[maxN], t_hws[maxN];
int s_maxls[maxN], t_maxls[maxN];
int ksm(int a, int b, int mod) {
    int res = 1, base = a;
    while (b) {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}
void debug() {
    // fprintf(stderr, "%s\n%s\n", s + 1, t + 1);
    // for (int i = 1; i <= n; i++) {
    //     cerr << s_hwp[i] << " \n"[i == n];
    // }
    // for (int i = 1; i <= m; i++) {
    //     cerr << t_hwp[i] << " \n"[i == m];
    // }
    // for (int i = 1; i <= n; i++) {
    //     cerr << s_hws[i] << " \n"[i == n];
    // }
    // for (int i = 1; i <= m; i++) {
    //     cerr << t_hws[i] << " \n"[i == m];
    // }
    // for (int i = 1; i <= n; i++) {
    //     cerr << s_maxls[i] << " \n"[i == n];
    // }
    // for (int i = 1; i <= m; i++) {
    //     cerr << t_maxls[i] << " \n"[i == m];
    // }
}
signed main() {
    cin >> n >> m;
    if (n == 1 || m == 1) {
        return cout << "-1", 0;
    }
    scanf("%s%s", s + 1, t + 1);
    for (int i = 1, j = m; i < j; i++, j--) {
        char tmp;
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
    }
    if (n > m) {
        swap(n, m);
        strcpy(tmp, s + 1);
        strcpy(s + 1, t + 1);
        strcpy(t + 1, tmp);
    }
    for (int i = 1; i <= n; i++) {
        s_hashp[1][i] = (s_hashp[1][i - 1] * base1 + s[i] - 'a' + 1) % mod1;
        s_hashp[2][i] = (s_hashp[2][i - 1] * base2 + s[i] - 'a' + 1) % mod2;
        ss_hashp[1][i] = ((s[i] - 'a' + 1) * ksm(base1, i - 1, mod1) % mod1 + ss_hashp[1][i - 1]) % mod1;
        ss_hashp[2][i] = ((s[i] - 'a' + 1) * ksm(base2, i - 1, mod2) % mod2 + ss_hashp[2][i - 1]) % mod2;
        // cerr << s_hashp[1][i] << " " << ss_hashp[1][i] << endl;
        if (s_hashp[1][i] == ss_hashp[1][i] && s_hashp[2][i] == ss_hashp[2][i]) {
            // cout << i << " ";
            s_hwp[i] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        t_hashp[1][i] = (t_hashp[1][i - 1] * base1 + t[i] - 'a' + 1) % mod1;
        t_hashp[2][i] = (t_hashp[2][i - 1] * base2 + t[i] - 'a' + 1) % mod2;
        tt_hashp[1][i] = ((t[i] - 'a' + 1) * ksm(base1, i - 1, mod1) % mod1 + tt_hashp[1][i - 1]) % mod1;
        tt_hashp[2][i] = ((t[i] - 'a' + 1) * ksm(base2, i - 1, mod2) % mod2 + tt_hashp[2][i - 1]) % mod2;
        // cerr << t_hashp[1][i] << " " << tt_hashp[1][i] << endl;
        if (t_hashp[1][i] == tt_hashp[1][i] && t_hashp[2][i] == tt_hashp[2][i]) {
            t_hwp[i] = 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        s_hashs[1][i] = (s_hashs[1][i + 1] * base1 + s[i] - 'a' + 1) % mod1;
        s_hashs[2][i] = (s_hashs[2][i + 1] * base2 + s[i] - 'a' + 1) % mod2;
        ss_hashs[1][i] = ((s[i] - 'a' + 1) * ksm(base1, n - i, mod1) % mod1 + ss_hashs[1][i + 1]) % mod1;
        ss_hashs[2][i] = ((s[i] - 'a' + 1) * ksm(base2, n - i, mod2) % mod2 + ss_hashs[2][i + 1]) % mod2;
        if (s_hashs[1][i] == ss_hashs[1][i] && s_hashs[2][i] == ss_hashs[2][i]) {
            s_hws[i] = 1;
            s_maxls[i] = n - i + 1;
        } else {
            s_maxls[i] = s_maxls[i + 1];
        }
    }
    for (int i = m; i >= 1; i--) {
        t_hashs[1][i] = (t_hashs[1][i + 1] * base1 + t[i] - 'a' + 1) % mod1;
        t_hashs[2][i] = (t_hashs[2][i + 1] * base2 + t[i] - 'a' + 1) % mod2;
        tt_hashs[1][i] = ((t[i] - 'a' + 1) * ksm(base1, m - i, mod1) % mod1 + tt_hashs[1][i + 1]) % mod1;
        tt_hashs[2][i] = ((t[i] - 'a' + 1) * ksm(base2, m - i, mod2) % mod2 + tt_hashs[2][i + 1]) % mod2;
        if (t_hashs[1][i] == tt_hashs[1][i] && t_hashs[2][i] == tt_hashs[2][i]) {
            t_hws[i] = 1;
            t_maxls[i] = m - i + 1;
        } else {
            t_maxls[i] = t_maxls[i + 1];
        }
    }
    for (int i = n, j = m; i >= 1 && j >= 1; i--, j--) {
        if (s[i] != t[j]) {
            while (i >= 1) {
                s_maxls[i] = s_maxls[i + 1];
                i--;
            }
            while (j >= 1) {
                t_maxls[j] = t_maxls[j + 1];
                j--;
            }
            break;
        }
    }
    debug();
    int res = -1;
    for (int i = 1; i < n && s[i] == t[i]; i++) {
        if (s_hwp[i] && t_hwp[i]) {
            res = max(res, i + s_maxls[i + 1]);
        }
    }
    cout << (res == -1 ? res : res * 2);
    return 0;
}