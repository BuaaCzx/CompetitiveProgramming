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
int n;
pair<int, int> a[maxN];
void solve() {
    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        cout << a[i].first << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++)
        cout << a[i].second << " ";
    cout << "\n";
}
int main() {
    ios;
    cf;
    return 0;
}