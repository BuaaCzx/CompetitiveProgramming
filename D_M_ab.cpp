#include <bits/stdc++.h>
using namespace std;
int main() {
    long long m, n, res = 1e18;
    cin >> n >> m;
    for (long long i = 1; i * i <= m && i <= n; i++) {
        long long j = m / i;
        if (i * j < m) {
            j++;
        }
        if (j > n)
            continue;
        res = min(res, i * j);
    }
    cout << res;
    return 0;
}