#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int N = 2e4 + 5;
int n, res;
pii sgm[N];
vector<pii> v;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sgm[i].first >> sgm[i].second;
    }
    sort(sgm + 1, sgm + 1 + n);
    v.push_back(sgm[1]);
    for (int i = 2; i <= n; i++) {
        if (sgm[i].first > v.back().second) {
            v.push_back(sgm[i]);
        } else {
            v.back().second = max(sgm[i].second, v.back().second);
        }
    }
    for (auto [l, r] : v) {
        res += r - l; // 区间长度
    }
    cout << res;
    return 0;
}