#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
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
const int inf = 0x7fffffff, maxN = (1 << 16) + 5;
const double eps = 1e-8;
void solve() {
}
int n, deg[maxN], fa[maxN], m;
vector<pii> res;
int main() {
    ios;
    queue<int> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> deg[i] >> fa[i];
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (fa[cur] == cur || deg[cur] != 1)
            continue;
        res.push_back(mp(min(cur, fa[cur]), max(cur, fa[cur])));
        //    cerr << cur << " " << fa[cur] << "\n";
        fa[fa[cur]] ^= cur;
        deg[fa[cur]]--;
        if (deg[fa[cur]] == 1) {
            q.push(fa[cur]);
        }
    }
    sort(res.begin(), res.end());
    int sz = res.size();
    for (int i = 0; i < sz; i++) {
        if (i == 0 || res[i] != res[i - 1]) {
            m++;
        }
    }
    cout << m << "\n";
    for (int i = 0; i < sz; i++) {
        if (i == 0 || res[i] != res[i - 1]) {
            cout << res[i].first << " " << res[i].second << "\n";
        }
    }
    return 0;
}