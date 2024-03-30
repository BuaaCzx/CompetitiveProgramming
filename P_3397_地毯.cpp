#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, b[N][N], a[N][N];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1, x[2], y[2]; i <= m; i++) {
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        b[x[0]][y[0]]++, b[x[0]][y[1] + 1]--, b[x[1] + 1][y[0]]--, b[x[1] + 1][y[1] + 1]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j];
            cout << a[i][j] << " \n"[j == n];
            // cerr << b[i][j] << " \n"[j == n];
        }
    }
    return 0;
}