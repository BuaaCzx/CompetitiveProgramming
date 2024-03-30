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
#define cf int _;cin >> _;while (_--) {solve();}
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int inf = 0x7fffffff, maxN = 2e5 + 5;
const double eps = 1e-8;
int a[55], n, res;
void solve() {
    res = 0;
    cin >> n;
    rep (i, 1, n) {
        cin >> a[i];
    }
    rep(i, 2, n) {
        int ma = max(a[i], a[i - 1]), mi = min(a[i], a[i - 1]);
        while (mi * 2 < ma) {
            res++, mi *= 2;
        }
    }
    cout << res<< endl;
}
int main() {
    ios;
    cf;
    return 0;
}