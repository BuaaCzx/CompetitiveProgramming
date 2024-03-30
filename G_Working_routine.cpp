#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
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
int n, m, q, v[1005][1005];
struct node {
    pii up, down, left, right;
} lis[1005][1005];
pii run(pii p, int x, int y) {
    for (int i = 0; i < x; i++) {
        p = lis[p.first][p.second].down;
    }
    for (int i = 0; i < y; i++) {
        p = lis[p.first][p.second].right;
    }
    return p;
}
int main() {
    ios;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            lis[i][j] = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
        }
    }
    int a, b, c, d, h, w;
    while (q--) {
        cin >> a >> b >> c >> d >> h >> w;
        pii pp1 = run({0, 0}, a, b), pp11 = run({0, 0}, c, d);
        pii pp2 = run({0, 0}, a + h - 1, b), pp22 = run({0, 0}, c + h - 1, d);
        for (int j = 0; j < w; j++) {
            lis[lis[pp1.first][pp1.second].up.first][lis[pp1.first][pp1.second].up.second].down = pp11;
            lis[lis[pp11.first][pp11.second].up.first][lis[pp11.first][pp11.second].up.second].down = pp1;
            lis[lis[pp2.first][pp2.second].down.first][lis[pp2.first][pp2.second].down.second].up = pp22;
            lis[lis[pp22.first][pp22.second].down.first][lis[pp22.first][pp22.second].down.second].up = pp2;
            swap(lis[pp1.first][pp1.second].up, lis[pp11.first][pp11.second].up);
            swap(lis[pp2.first][pp2.second].down, lis[pp22.first][pp22.second].down);
            pp1 = lis[pp1.first][pp1.second].right;
            pp11 = lis[pp11.first][pp11.second].right;
            pp2 = lis[pp2.first][pp2.second].right;
            pp22 = lis[pp22.first][pp22.second].right;
        }
        pp1 = run({0, 0}, a, b), pp11 = run({0, 0}, c, d);
        pp2 = run({0, 0}, a, b + w - 1), pp22 = run({0, 0}, c, d + w - 1);
        for (int i = 0; i < h; i++) {
            lis[lis[pp1.first][pp1.second].left.first][lis[pp1.first][pp1.second].left.second].right = pp11;
            lis[lis[pp11.first][pp11.second].left.first][lis[pp11.first][pp11.second].left.second].right = pp1;
            lis[lis[pp2.first][pp2.second].right.first][lis[pp2.first][pp2.second].right.second].left = pp22;
            lis[lis[pp22.first][pp22.second].right.first][lis[pp22.first][pp22.second].right.second].left = pp2;
            swap(lis[pp1.first][pp1.second].left, lis[pp11.first][pp11.second].left);
            swap(lis[pp2.first][pp2.second].right, lis[pp22.first][pp22.second].right);
            pp1 = lis[pp1.first][pp1.second].down;
            pp11 = lis[pp11.first][pp11.second].down;
            pp2 = lis[pp2.first][pp2.second].down;
            pp22 = lis[pp22.first][pp22.second].down;
        }
        // pii pp = lis[0][1].down;
        // for (int i = 1; i <= n; i++) {
        //     pii poi = pp;
        //     for (int j = 1; j <= m; j++) {
        //         cerr << poi.first << "," << poi.second << " ";
        //         poi = lis[poi.first][poi.second].right;
        //     }
        //     pp = lis[pp.first][pp.second].down;
        //     cerr << "\n";
        // }
        // cerr << "\n";
    }
    pii pp = lis[0][1].down;
    for (int i = 1; i <= n; i++) {
        pii poi = pp;
        for (int j = 1; j <= m; j++) {
            cout << v[poi.first][poi.second] << " ";
            poi = lis[poi.first][poi.second].right;
        }
        pp = lis[pp.first][pp.second].down;
        cout << "\n";
    }
    return 0;
}