#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define pr printf
#define sc scanf
#define mem(a, k) memset(a, k, sizeof(a))
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define per(i, a, b) for (ll i = (a); i >= (b); i--)
#define cf        \
    int _;        \
    cin >> _;     \
    while (_--) { \
        solve();  \
    }
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
const int inf = 0x7fffffff, maxN = 2e5 + 5;
const double eps = 1e-8;
int res;
int n, a, b;
void dfs(int l, int r) {
    res++;
    int mid = (l + r) / 2;
    //   cout << l << " " << mid << endl;
    if ((l <= a && a <= mid && l <= b && b <= mid)) {
        //    cout << "!!!n";
        dfs(l, mid);
    } else if ((mid < a && a <= r && mid < b && b <= r)) {
        dfs(mid + 1, r);
    } else {
        return;
    }
}
int main() {
    ios;
    cin >> n >> a >> b;
    int sum = -1;
    dfs(1, n);
    while (n) {
        sum++, n >>= 1;
    }

    //    cout << res << endl;
    if (sum + 1 - res == sum) {
        cout << "Final!";
    } else
        cout << sum + 1 - res;
    return 0;
}