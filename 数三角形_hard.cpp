#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char g[N][N];
int l[N][N], r[N][N], u[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> (g[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '*') {
                l[i][j] = min(l[i][j - 1], u[i - 1][j - 1]) + 1;
                u[i][j] = u[i - 1][j] + 1;
            }
        }
        for (int j = m; j >= 1; j--) {
            if (g[i][j] == '*') {
                r[i][j] = min(r[i][j + 1], u[i - 1][j + 1]) + 1;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '*') {
                res += min({l[i][j], r[i][j], (u[i][j] + 1) / 2});
            }
        }
    }
    cout << res << endl;
    return 0;
}
