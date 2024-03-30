#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
char s[N];
long long res;
void solve() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int l = 1, r = 2; r <= len; r++, l++) {
        int ll = l, rr = r;
        int fl = 0;
        while (ll >= 1 && rr <= len) {
            if (s[ll] > s[rr]) {
                fl = 1;
            } else if (s[ll] < s[rr]) {
                fl = -1;
            }
            if (fl == 1)
                res++;
            ll--, rr++;
        }
    }
    for (int i = 1; i <= len; i++) {
        int ll = i, rr = i;
        int fl = 0;
        while (ll >= 1 && rr <= len) {
            if (s[ll] > s[rr]) {
                fl = 1;
            } else if (s[ll] < s[rr]) {
                fl = -1;
            }
            if (fl == 1)
                res++;
            ll--, rr++;
        }
    }
    cout << res << endl;
}
int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}