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
const int inf = 0x7fffffff, maxN = 2e5 + 5;
const double eps = 1e-8;
int n, cnt[205];
long long res = 0;
int f(int s1, int s2) {
    return stoi(to_string(s1) + to_string(s2));
}
map<string, int> m;
int calc(string s) {
    int res = 0;
    for (auto c : s)
        res += c - '0';
    return res % 9;
}
string s[maxN];
long long tonum(string s) {
    long long res = 0;
    for (auto c : s)
        res = res * 10 + c - '0';
    return res;
}
int cnt2[11][55];
signed main() {
    ios;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> s[i];
        cnt[calc(s[i])]++;
        cnt2[(s[i].back() - '0') & 1][calc(s[i])]++;
    }
    for (int i = 1, x; i <= n; i++) {
        x = tonum(s[i]);
        if (s[i].length() != 1 && x % 4 == 0) {
            res += cnt[(9 - calc(s[i])) % 9];
        } else if (s[i].length() == 1 && x % 2 == 0) {
            if (x == 0 || x == 4 || x == 8) {
                res += cnt2[0][(9 - calc(s[i])) % 9];
            } else {
                res += cnt2[1][(9 - calc(s[i])) % 9];
            }
        }
        if (x % 36 == 0)
            res--;
    }
    cout << res;
    return 0;
}