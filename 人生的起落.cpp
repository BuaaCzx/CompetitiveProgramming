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
int res[maxN];
void solve() {
    int n, s, k;
    cin >> n >> s >> k;
    if (k == 0) {
        for (int i = 1; i <= n - 1; i++) {
            cout << 1 << " ";
        }
        cout << s - (n - 1) << "\n";
        return;
    }
    if (k > (n - 1) / 2) {
        cout << "-1\n";
    } else {
        int sum = 0;
        for (int i = 1, cur = 2; i <= 2 * k + 1; i++) {
            res[i] = cur;
            sum += cur;
            cur = cur == 1 ? 2 : 1;
        }
        for (int i = 2 * k + 2; i <= n; i++)
            res[i] = 1, sum += 1;
        if (sum > s) {
            cout << "-1\n";
            return;
        }
        int d = s - sum;
        if (n % 2 == 1 && k == (n - 1) / 2) {
            int cnt1 = n / 2, cnt2 = n - cnt1, ok = 0;
            for (int i = 0; i * cnt2 <= d; i++) {
                if (d - i * cnt2 <= i * cnt1) {
                    // cerr << "###" << i;
                    ok = 1;
                    for (int j = 1, dd = d - i * cnt2; j <= n; j++) {
                        if (j % 2 == 0) {
                            int x = min(i, dd);
                            res[j] += x, dd -= x;
                        } else {
                            res[j] += i;
                        }
                    }
                    break;
                }
            }
            if (!ok) {
                cout << "-1\n";
                return;
            }
        } else {
            if (n % 2 == 0) {
                res[n] += d;
            } else {
                res[n - 1] += d;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
}
signed main() {
    ios;
    cf;
    return 0;
}