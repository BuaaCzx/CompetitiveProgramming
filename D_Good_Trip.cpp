#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, maxn = 2e5 + 5;
long long ksm(long long a, long long b) {
    long long base = a % mod, res = 1;
    while (b) {
        if (b & 1) {
            (res *= base) %= mod;
        }
        (base *= base) %= mod;
        b >>= 1;
    }
    return res;
}
int n, m, k;
long long fact[maxn];
void init() {
    // 预处理阶乘
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 2e5; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
long long inv(long long x) {
    return ksm(x, mod - 2);
}
long long c(int n, int m) {
    return fact[n] * inv(fact[n - m]) % mod * inv(fact[m]) % mod;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        long long sum = 0, res = 0;
        cin >> n >> m >> k;
        long long s = 1ll * (n - 1) * n / 2, revs = ksm(s, mod - 2);
        for (int i = 0, f; i < m; i++) {
            cin >> f >> f >> f;
            (sum += f) %= mod;
        }
        res += sum * k % mod * revs % mod;
        for (int i = 2; i <= k; i++) {
            (res += m * c(k, i) % mod * ksm(inv(s), i) % mod * ksm((s - 1) % mod * inv(s) % mod, k - i) % mod * (1ll * i * (i - 1) / 2 % mod) % mod) %= mod;
        }
        cout << res << "\n";
    }
    return 0;
}