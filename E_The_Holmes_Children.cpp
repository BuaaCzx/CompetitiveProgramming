#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5 + 5, M = 1e6 + 5;
const int mod = 1000000007;
int minp[M];
vector<int> primes;
void init() {
    for (int i = 2; i <= 1e6; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (1ll * p * i > 1e6) {
                break;
            }
            minp[p * i] = p;
            if (minp[i] == p) {
                break;
            }
        }
    }
}
ll phi(ll x) {
    ll res = x;
    for (auto p : primes) {
        if (1ll * p * p > x) {
            break;
        }
        if (x % p == 0) {
            res = res / p * (p - 1);
        }
        while (x % p == 0) {
            x /= p;
        }
    }
    if (x > 1) {
        res = res / x * (x - 1);
    }
    return res;
}
int main() {
    init();
    ll n, k;
    cin >> n >> k;
    k = (k + 1) >> 1;
    for (ll i = 0; i < k && n > 1; i++) {
        n = phi(n);
    }
    cout << n % mod;
    return 0;
}