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
string s[maxN];
int n, d[maxN];
int calc(char c) {
    rep (i, 1, n) {
        int cnt = 0;
        for (int j = 0; j < s[i].length(); j++) {
            cnt += s[i][j] == c;
        }
        d[i] = cnt - (s[i].length() - cnt);
    }
    sort(d + 1, d + n + 1, [](int x, int y) {
        return x > y;
    });
    if (d[1] == 0) {
        return 0;
    } else {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += d[i];
            if (sum <= 0) {
                return i - 1;
            }
        }
    }
    return n;
}
void solve() {
    int res = 0;
    cin >> n;
    rep (i, 1, n) {
        cin >> s[i];
    }
    for (char c = 'a'; c <= 'e'; c++) {
        res = max(res, calc(c));
    }
    cout << res << endl;
}
int main() {
    ios;
    cf;
    return 0;
}