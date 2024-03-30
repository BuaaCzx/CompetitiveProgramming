#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int maxN = 8e3 + 5;
int n, q, a[maxN];
pii b[maxN];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b, b + n);
    int op, x, v;
    while (q--) {
        cin >> op >> x;
        x--;
        if (op == 1) {
            cin >> v;
            int p = lower_bound(b, b + n, (pii){a[x], x}) - b;
            a[x] = v;
            b[p] = {a[x], x};
            for (int i = p + 1; i < n; i++) {
                if (b[i - 1] > b[i]) {
                    swap(b[i - 1], b[i]);
                } else {
                    break;
                }
            }
            for (int i = p - 1; i >= 0; i--) {
                if (b[i + 1] < b[i]) {
                    swap(b[i + 1], b[i]);
                } else {
                    break;
                }
            }
        } else {
            int p = lower_bound(b, b + n, (pii){a[x], x}) - b;
            cout << p + 1 << '\n';
        }
    }
    return 0;
}