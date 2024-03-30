#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 5;
int n, p, a[maxn], d[maxn];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    int l, r, x;
    while (p--) {
        cin >> l >> r >> x;
        d[l] += x, d[r + 1] -= x;
    }
    int res = 0x7fffffff, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += d[i];
        res = min(res, sum);
    }
    cout << res;
    return 0;
}