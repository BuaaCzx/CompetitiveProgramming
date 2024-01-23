#include <bits/stdc++.h>
using namespace std;
int n, m, h[1005][1005];
char c[1005][1005];
long long dp[1005], res;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            h[i][j] = c[i][j] == '.' ? h[i - 1][j] + 1 : 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        stack<int> st;
        for (int j = 1; j <= m; j++) {
            while (!st.empty() && h[i][st.top()] > h[i][j]) {
                st.pop();
            }
            if (st.empty()) {
                dp[j] = h[i][j] * j;
            } else {
                dp[j] = 1ll * dp[st.top()] + h[i][j] * (j - st.top());
            }
            st.push(j);
            res += dp[j];
            //    cerr << dp[j] << " ";
        }
        // cerr << endl;
    }
    cout << res;
    return 0;
}