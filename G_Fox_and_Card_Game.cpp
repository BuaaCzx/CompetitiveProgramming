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
int n, s, a[maxN];
long long res[2];
priority_queue<int> q;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int i = 0; i < s; i++) {
            cin >> a[i];
        }
        if (s & 1) {
            q.push(a[s / 2]);
        }
        for (int i = 0; i < s / 2; i++) {
            res[0] += a[i];
        }
        for (int i = (s & 1) ? s / 2 + 1 : s / 2; i < s; i++) {
            res[1] += a[i];
        }
    }
    int op = 0;
    while (!q.empty()) {
        res[op] += q.top(), q.pop(), op ^= 1;
    }
    cout << res[0] << " " << res[1];
}
int main() {
    ios;
    solve();
    return 0;
}