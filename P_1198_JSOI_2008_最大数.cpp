#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
const int N = 2e5 + 5;
using ll = long long;
// #define int ll
struct node_t {
    int l, r;
    ll maxval;
} tr[N << 2];
ll read() {
    char c = getchar();
    ll num = 0;
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar())
        num = num * 10 + c - '0';
    return num;
}

void build(int u, int l, int r) {
    tr[u].l = l;
    tr[u].r = r;
    if (l == r)
        tr[u].maxval = LONG_LONG_MIN;
    else {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].maxval = LONG_LONG_MIN;
    }
}

void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) {
        tr[u].maxval = v;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid)
        modify(u << 1, x, v);
    else
        modify(u << 1 | 1, x, v);
    tr[u].maxval = max(tr[u << 1].maxval, tr[u << 1 | 1].maxval);
}
ll query(int u, int l, int r) {
    if (tr[u].r < l || tr[u].l > r)
        return LONG_LONG_MIN;
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u].maxval;
    int mid = tr[u].l + tr[u].r >> 1;
    ll a = LONG_LONG_MIN, b = LONG_LONG_MIN;
    if (l <= mid)
        a = query(u << 1, l, r);
    if (r > mid)
        b = query(u << 1 | 1, l, r);
    return max(a, b);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, d;
    cin >> m >> d;
    ll t = 0, idx = 0;
    build(1, 1, N);
    while (m--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int x;
            cin >> x;
            modify(1, ++idx, (x + t) % d);
        }

        else {
            int L;
            cin >> L;
            t = query(1, idx - L + 1, idx);
            cout << t << '\n';
        }
    }

    return 0;
}