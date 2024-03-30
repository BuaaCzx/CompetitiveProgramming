#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, w[maxn], v[maxn], l[maxn], r[maxn];
long long s;
int sum[maxn];
long long sum2[maxn];
long long calc(int W) {
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (w[i] >= W);
        sum2[i] = sum2[i - 1] + (w[i] >= W) * v[i];
    }
    for (int i = 1; i <= m; i++) {
        res += (sum[r[i]] - sum[l[i] - 1]) * (sum2[r[i]] - sum2[l[i] - 1]);
    }
    // cerr << W << " " << res << endl;
    return res;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i];
    int left = 0, right = 1e6;
    while (left < right) {
        //    cerr << left << " " << right << " ";
        int mid = (left + right) >> 1;
        if (calc(mid) <= s) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    // cout << left << endl; // 输出左边界
    if (left > 1e6) {
        cout << calc(1e6) - s;
    } else {
        cout << min(s - calc(left), calc(left - 1) - s);
    }
    return 0;
}