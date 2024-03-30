#include <stdio.h>
// l-a<=k*m<=r-a
int main() {
    long long a, m, l, r;
    scanf("%lld%lld%lld%lld", &a, &m, &l, &r);
    l -= a, r -= a;
    if (r % m != 0)
        r = r >= 0 ? r / m * m : r / m * m - m;
    if (r >= l)
        printf("%lld", (r - l) / m + 1);
    else
        puts("0");
    return 0;
}