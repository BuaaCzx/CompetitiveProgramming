#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
const double eps = 1e-7;
int n;
double a[maxN], b[maxN];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n, [](double x, double y) {
        return x > y;
    });
    sort(b, b + n, [](double x, double y) {
        return x > y;
    });
    int pa = 0, pb = 0;
    double res = 0.0, suma = 0.0, sumb = 0.0;
    while (pa < n && pb < n) {
        if (suma < sumb) {
            suma += a[pa];
            pa++;
        } else {
            sumb += b[pb];
            pb++;
        }
        suma -= 1.0, sumb -= 1.0;
        res = max(res, min(suma, sumb));
    }
    while (pa < n) {
        suma += a[pa];
        pa++;
        suma -= 1.0, sumb -= 1.0;
        res = max(res, min(suma, sumb));
    }
    while (pb < n) {
        sumb += b[pb];
        pb++;
        suma -= 1.0, sumb -= 1.0;
        res = max(res, min(suma, sumb));
    }
    printf("%.4lf", res);
    return 0;
}