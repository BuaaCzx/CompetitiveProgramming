#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define pr printf
#define sc scanf
#define pii pair<int, int>
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
vector<int> v[maxN];
int n, a[maxN], b[maxN], res;
struct node {
    int l, r, minn;
} tr[maxN << 2];
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    if (l == r) {
        tr[x].minn = b[l];
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
    tr[x].minn = min(tr[x << 1].minn, tr[x << 1 | 1].minn);
    return;
}
void update(int x, int pos, int val) {
    if (tr[x].l == tr[x].r) {
        tr[x].minn = val;
        return;
    }
    int mid = tr[x].l + tr[x].r >> 1;
    if (pos <= mid)
        update(x << 1, pos, val);
    else
        update(x << 1 | 1, pos, val);
    tr[x].minn = min(tr[x << 1].minn, tr[x << 1 | 1].minn);
    return;
}
int query(int x, int l, int r) {
    if (l >= tr[x].l && r <= tr[x].r) {
        return tr[x].minn;
    }
    int mid = tr[x].l + tr[x].r >> 1, res = inf;
    if (l <= mid) {
        res = min(res, query(x << 1, l, r));
    }
    if (r > mid) {
        res = min(res, query(x << 1 | 1, l, r));
    }
    return res;
}
void solve() {
    res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        b[i] = inf;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]].pb(i);
        b[a[i]] = i;
    }
    build(1, 1, n);
    int curr = n;
    while (curr <= n) {
        res++;
        int l = query(1, 1, curr);
        for (int i = l; i <= curr; i++) {
            v[a[i]].pop_back();
            if (v[a[i]].empty()) {
                update(1, a[i], inf);
            } else {
                update(1, a[i], v[a[i]].back());
            }
        }
        curr = l - 1;
        //    cerr << curr << "\n";
    }
    // cerr << "\n";
    cout << res - 1 << "\n";
}
int main() {
    ios;
    cf;
    return 0;
}