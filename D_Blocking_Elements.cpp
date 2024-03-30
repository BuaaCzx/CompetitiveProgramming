//O2优化
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define mi(x, y) ((x) < (y) ? (x) : (y))
#define ma(x, y) ((x) > (y) ? (x) : (y))    
const int maxN = 2e5 + 5;
const long long inf = 1e18;
int n, a[maxN];
long long dp[maxN], sum[maxN];
bool check(long long x) {
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = dp[q.front()] + a[i];
        while (!q.empty() && dp[q.back()] >= dp[i]) {
            q.pop_back();
        }
        while (!q.empty() && sum[i] - sum[q.front()] > x) {
            q.pop_front();
        }
        q.push_back(i);
    }
    return dp[n + 1] <= x;
}
void solve() {
    long long l = -1, r = 0, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        l = ma(l, a[i]), r += a[i];
    }
    a[n + 1] = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            res = mid, r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}