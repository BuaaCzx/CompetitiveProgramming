#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e4 + 5;
int n, k, a[maxN], b[maxN], tot;
int res[2][maxN], ans; // res[0][i] 表示0-i的最大数量，res[1][i] 表示i-n-1的最大数量
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int r = 0, tmp = {0};
    for (int i = 0; i < n; i++) {
        while (a[r] - a[i] <= k && r < n) {
            res[0][r] = max(r == 0 ? 0 : res[0][r - 1], r - i + 1);
            r++;
        }
    }
    int l = n - 1;
    tmp = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (a[i] - a[l] <= k && l >= 0) {
            res[1][l] = max(res[1][l + 1], i - l + 1);
            l--;
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, res[0][i] + res[1][i + 1]);
    }
    cout << ans;
    return 0;
}