#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, a[maxn], sum[maxn];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}