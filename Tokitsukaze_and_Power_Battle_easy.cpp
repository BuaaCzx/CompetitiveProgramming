#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e5 + 5;
const long long inf = 1e18;
int n, q, a[maxN];
long long sum[maxN];
struct node {
    int l, r;
    long long maxx, sum, add_tag;
} tr[maxN << 2];
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r, tr[x].add_tag = 0;
    if (l == r) {
        tr[x].maxx = sum[l] - 2 * a[l];
        tr[x].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    tr[x].maxx = max(tr[x << 1].maxx, tr[x << 1 | 1].maxx);
    tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;
}
void modify_sum(int x, int pos, int v) {
    if (tr[x].l == tr[x].r) {
        tr[x].sum = v;
        return;
    }
    int mid = (tr[x].l + tr[x].r) >> 1;
    if (pos <= mid)
        modify_sum(x << 1, pos, v);
    else
        modify_sum(x << 1 | 1, pos, v);
    tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;
}
long long query_sum(int x, int l, int r) {
    if (tr[x].l >= l && tr[x].r <= r)
        return tr[x].sum;
    int mid = (tr[x].l + tr[x].r) >> 1;
    long long res = 0;
    if (l <= mid)
        res += query_sum(x << 1, l, r);
    if (r > mid)
        res += query_sum(x << 1 | 1, l, r);
    return res;
}
void push_down(int x) {
    if (tr[x].l == tr[x].r)
        return;
    tr[x << 1].maxx += tr[x].add_tag;
    tr[x << 1 | 1].maxx += tr[x].add_tag;
    tr[x << 1].add_tag += tr[x].add_tag;
    tr[x << 1 | 1].add_tag += tr[x].add_tag;
    tr[x].add_tag = 0;
}
void modify_maxx(int x, int pos, int v) {
    if (tr[x].l == tr[x].r) {
        tr[x].maxx = query_sum(1, 1, pos) - 2 * v;
        return;
    }
    push_down(x);
    int mid = (tr[x].l + tr[x].r) >> 1;
    if (pos <= mid)
        modify_maxx(x << 1, pos, v);
    else
        modify_maxx(x << 1 | 1, pos, v);
    tr[x].maxx = max(tr[x << 1].maxx, tr[x << 1 | 1].maxx);
}
void modify_tradd(int x, int l, int r, int v) {
    if (l > r)
        return;
    if (tr[x].l >= l && tr[x].r <= r) {
        tr[x].maxx += (long long)v;
        tr[x].add_tag += v;
        return;
    }
    push_down(x);
    int mid = (tr[x].l + tr[x].r) >> 1;
    if (l <= mid)
        modify_tradd(x << 1, l, r, v);
    if (r > mid)
        modify_tradd(x << 1 | 1, l, r, v);
    tr[x].maxx = max(tr[x << 1].maxx, tr[x << 1 | 1].maxx);
}
long long query_maxx(int x, int l, int r) {
    if (tr[x].l >= l && tr[x].r <= r)
        return tr[x].maxx;
    push_down(x);
    int mid = (tr[x].l + tr[x].r) >> 1;
    long long res = -inf;
    if (l <= mid)
        res = max(res, query_maxx(x << 1, l, r));
    if (r > mid)
        res = max(res, query_maxx(x << 1 | 1, l, r));
    tr[x].maxx = max(tr[x << 1].maxx, tr[x << 1 | 1].maxx);
    return res;
}
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    build(1, 1, n);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            modify_sum(1, x, y);
            modify_maxx(1, x, y);
            modify_tradd(1, x + 1, n, y - a[x]);
            a[x] = y;
        } else {
            cout << query_maxx(1, x + 1, y) - query_sum(1, 1, x - 1) << "\n";
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
