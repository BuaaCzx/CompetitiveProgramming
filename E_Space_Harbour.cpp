#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
int n, m, q, x[maxn], v[maxn], t[maxn], l[maxn], r[maxn], a[maxn], b[maxn];
ll sum[maxn], ans[maxn];
vector<int> G[maxn];
vector<ll> f[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
        scanf("%d", &x[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%d", &t[i], &l[i], &r[i]);
        if (t[i] == 1)
            scanf("%d", &a[i]), b[i] = v[++m] = l[i], x[m] = r[i], l[i] = r[i] = m;
        else
            a[i] = lower_bound(x + 1, x + m + 1, l[i]) - x, b[i] = upper_bound(x + 1, x + m + 1, r[i]) - x - 1;
    }
    cout << "###\n";
    sort(x + 1, x + m + 1);
    for (int i = 1; i <= m; i++)
        sum[i] = sum[i - 1] + v[i];
    cout << "###\n";
    for (int i = m; i; i--) {
        while (G[i].size() >= 2 && (f[i][G[i].size() - 2] - f[i][G[i].size() - 1]) <= 1ll * x[i] * (G[i][G[i].size() - 2] - G[i][G[i].size() - 1]))
            G[i].pop_back(), f[i].pop_back();
        G[i].push_back(i), f[i].push_back(f[i].back() + 1ll * x[i] * (i - G[i][G[i].size() - 2]) - sum[i] + sum[G[i][G[i].size() - 2]]);
    }
    for (int i = 1; i <= q; i++)
        if (t[i] == 1) {
            int j = lower_bound(x + 1, x + m + 1, r[i]) - x;
            while (G[j].size() >= 2 && (f[j][G[j].size() - 2] - f[j][G[j].size() - 1]) <= 1ll * x[j] * (G[j][G[j].size() - 2] - G[j][G[j].size() - 1]))
                G[j].pop_back(), f[j].pop_back();
            G[j].push_back(j), f[j].push_back(f[j].back() + 1ll * x[j] * (j - G[j][G[j].size() - 2]) - sum[j] + sum[G[j][G[j].size() - 2]]);
        } else {
            int j = b[i], k = upper_bound(G[j].begin(), G[j].end(), a[i]) - G[j].begin() - 1;
            ans[i] = f[j][k] + 1ll * x[j] * (a[i] - G[j][k]) - sum[j] + sum[G[j][k]];
        }
    cout << "1";
    for (int i = 1; i <= q; i++) {
        printf("%d\n", t[i]);
        if (t[i] == 2)
            printf("%lld\n", ans[i]);
    }

    return 0;
}
