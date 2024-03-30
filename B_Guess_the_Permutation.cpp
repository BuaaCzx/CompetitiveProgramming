#include <bits/stdc++.h>
using namespace std;
#define int ll
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
int query(int l, int r) {
    int res;
    cout << "? " << l << " " << r << endl;
    cout.flush();
    cin >> res;
    return res;
}
void solve() {
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (query(1, mid) > 0) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    int i = l;
    int j = i + (query(i, n) - query(i + 1, n)) + 1;
    int k = j + (query(j, n) - query(j + 1, n));
    cout << "! " << i << " " << j << " " << k << endl;
    cout.flush();
}
signed main() {
    ios;
    cf;
    return 0;
}