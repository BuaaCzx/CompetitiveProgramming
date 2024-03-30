#include <stdio.h>

void solve() {
    long long x;
    scanf("%lld", &x);
    long long cnt = 0, res = 0;
    for (int i = 62; i >= 0; i--) {
        cnt += (x >> i) & 1;
    }
    for (int i = 0; i < cnt; i++) {
        res = res << 1 | 1;
    }
    printf("%lld %lld\n", cnt, res);
}

int main() {
    int T = 1;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}