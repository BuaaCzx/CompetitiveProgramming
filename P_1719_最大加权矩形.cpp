#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, a[maxn][maxn], sum[maxn][maxn], res = -2e9;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    for (int x1 = 1; x1 <= n; x1++)
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = x1; x2 <= n; x2++)
                for (int y2 = y1; y2 <= n; y2++) {
                    res = max(res, sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
                }
        }
    cout << res << endl;
    return 0;
}