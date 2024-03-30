#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, l, r, dp[maxn], a[maxn];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    deque<int> q;
    q.push_back(n + 1);
    for (int i = n; i >= 0; i--) {
        if (i + l > n) {
            dp[i] = a[i];
        } else {
            while (!q.empty() && q.front() > i + r)
                q.pop_front();
            while (!q.empty() && dp[q.back()] <= dp[i + l])
                q.pop_back();
            q.push_back(i + l);
            dp[i] = a[i] + dp[q.front()];
        }
    }
    cout << dp[0];
    return 0;
}