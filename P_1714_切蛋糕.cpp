#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], sum[maxn], res = -2e9;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && i - q.front() > m) {
            q.pop_front();
        }
        res = max(res, sum[i] - sum[q.front()]);
        while (!q.empty() && sum[i] < sum[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << res;
    return 0;
}