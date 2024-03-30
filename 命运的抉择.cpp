// 优化
// O2
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
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
const int inf = 0x7fffffff, maxN = 1e6 + 5;
const double eps = 1e-8;
vector<int> primes;
int minp[maxN], ok[maxN];
void init() {
    for (int i = 2; i <= 1e3; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.pb(i);
        }
        for (auto p : primes) {
            if (1ll * p * i > 1e3)
                break;
            minp[p * i] = p;
            if (i % p == 0)
                break;
        }
    }
}
int n, a[maxN], aa[maxN];
int fa[maxN];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int a, int b) { fa[find(a)] = find(b); }
vector<vector<int>> vv(maxN);
void solve() {
    vector<int> b, c;
    unordered_set<int> s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        aa[i] = a[i];
        fa[i] = i;
    }
    for (auto p : primes) {
        if (p > 1e3)
            break;
        int u = -1;
        for (int i = 1; i <= n; i++) {
            if (aa[i] % p == 0) {
                while (aa[i] % p == 0)
                    aa[i] /= p;
                if (u == -1)
                    u = i;
                else
                    merge(u, i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (aa[i] > 1e3) {
            s.insert(aa[i]);
            vv[aa[i]].pb(i);
        }
    }
    for (auto i : s) {
        int u = vv[i][0];
        for (auto x : vv[i]) {
            merge(x, u);
        }
        vv[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        if (find(i) != find(1)) {
            for (int j = 1; j <= n; j++) {
                if (find(j) == find(1)) {
                    b.pb(j);
                } else {
                    c.pb(j);
                }
            }
            break;
        }
    }
    if (b.empty()) {
        cout << "-1 -1\n";
    } else {
        cout << b.size() << " " << c.size() << "\n";
        for (auto x : b) {
            cout << a[x] << " ";
        }
        cout << "\n";
        for (auto x : c) {
            cout << a[x] << " ";
        }
        cout << "\n";
    }
}
signed main() {
    init();
    ios;
    cf;
    return 0;
}

// 优化
// O2
// #pragma GCC optimize("O2")
// #pragma GCC optimize("O3")
// #include <bits/stdc++.h>
// using namespace std;
// #define int ll
// #define pb push_back
// #define mp make_pair
// #define ll long long
// #define ull unsigned long long
// #define pr printf
// #define sc scanf
// #define mem(a, k) memset(a, k, sizeof(a))
// #define rep(i, a, b) for (ll i = (a); i <= (b); i++)
// #define per(i, a, b) for (ll i = (a); i >= (b); i--)
// #define cf        \
//     int _;        \
//     cin >> _;     \
//     while (_--) { \
//         solve();  \
//     }
// #define ios                      \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int inf = 0x7fffffff, maxN = 1e6 + 5;
// const double eps = 1e-8;
// vector<int> primes;
// int minp[maxN], ok[maxN];
// void init() {
//     for (int i = 2; i <= 1e6; i++) {
//         if (!minp[i]) {
//             minp[i] = i;
//             primes.pb(i);
//         }
//         for (auto p : primes) {
//             if (1ll * p * i > 1e6)
//                 break;
//             minp[p * i] = p;
//             if (i % p == 0)
//                 break;
//         }
//     }
// }

// int n, a[maxN];
// int fa[maxN];
// int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
// void merge(int a, int b) { fa[find(a)] = find(b); }
// vector<vector<int>> vv(maxN);
// void solve() {
//     vector<int> b, c;
//     unordered_set<int> s;
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//         fa[i] = i;
//         if (minp[a[i]] == a[i] && a[i] > 1e3) {
//             vv[a[i]].pb(i);
//             s.insert(a[i]);
//         }
//     }
//     for (auto i : s) {
//         int u = vv[i][0];
//         for (auto x : vv[i]) {
//             merge(x, u);
//         }
//         vv[i].clear();
//     }
//     for (auto p : primes) {
//         if (p > 1e3)
//             break;
//         int u = -1;
//         for (int i = 1; i <= n; i++) {
//             if (a[i] % p == 0) {
//                 if (u == -1)
//                     u = i;
//                 else
//                     merge(u, i);
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         if (find(i) != find(1)) {
//             for (int j = 1; j <= n; j++) {
//                 if (find(j) == find(1)) {
//                     b.pb(j);
//                 } else {
//                     c.pb(j);
//                 }
//             }
//             break;
//         }
//     }
//     if (b.empty()) {
//         cout << "-1 -1\n";
//     } else {
//         cout << b.size() << " " << c.size() << "\n";
//         for (auto x : b) {
//             cout << a[x] << " \n"[x == *b.rbegin()];
//         }
//         for (auto x : c) {
//             cout << a[x] << " \n"[x == *c.rbegin()];
//         }
//     }
// }
// signed main() {
//     init();
//     ios;
//     cf;
//     return 0;
// }