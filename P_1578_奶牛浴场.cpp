#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ma(x, y) ((x) > (y) ? (x) : (y))
#define mi(x, y) ((x) < (y) ? (x) : (y))
const int maxn = 5e3 + 15;
int l, w, n, res;
pii a[maxn];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> l >> w >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        a[i] = {x, y};
    }
    a[n++] = {0, 0}, a[n++] = {0, w}, a[n++] = {l, 0}, a[n++] = {l, w};
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int up = w, down = 0;
        for (int j = i + 1; j < n; j++) {
            res = max(res, (a[j].first - a[i].first) * (up - down));
            if (a[j].second >= a[i].second) {
                up = min(up, a[j].second);
            }
            if (a[j].second <= a[i].second) {
                down = max(down, a[j].second);
            }
        }
    }
    sort(a, a + n, [](pii x, pii y) {
        return x.second < y.second;
    });
    for (int i = 0; i < n; i++) {
        int left = 0, right = l;
        for (int j = i + 1; j < n; j++) {
            res = max(res, (a[j].second - a[i].second) * (right - left));
            if (a[j].first >= a[i].first) {
                right = min(right, a[j].first);
            }
            if (a[j].first <= a[i].first) {
                left = max(left, a[j].first);
            }
        }
    }
    cout << res;
    return 0;
}