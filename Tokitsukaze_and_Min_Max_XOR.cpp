#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, a[N], k;

long long ksm(int a, int b) {
    int base = a, res = 1;
    while (b) {
        if (b & 1)
            res = 1ll * res * base % mod;
        base = 1ll * base * base % mod;
        b >>= 1;
    }
    return res;
}

long long inv(int x) {
    return ksm(x, mod - 2);
}

class Trie {
private:
    struct node {
        long long nxt[2], cnt, val;
    };
    int tot = 0;
    vector<node> tr;

public:
    Trie(int sz) {
        tr.resize(sz * 32, {{0, 0}, 0, 0});
    }

    void insert(int v, int pos) {
        int x = 0;
        for (int i = 30; i >= 0; i--) {
            int nxt = v >> i & 1;
            if (!tr[x].nxt[nxt]) {
                tr[x].nxt[nxt] = ++tot;
                tr[tr[x].nxt[nxt]].val = tr[tr[x].nxt[nxt]].cnt = 0;
            }
            x = tr[x].nxt[nxt];
            tr[x].cnt++;
            tr[x].val = (tr[x].val + inv(ksm(2, pos + 1))) % mod;
        }
    }

    long long query(int v) {
        long long res = 0, x = 0;
        for (int i = 30; i >= 0; i--) {
            int bitv = v >> i & 1, bitk = k >> i & 1;
            if (bitk == 1 && tr[x].nxt[bitv]) {
                res = (res + tr[tr[x].nxt[bitv]].val) % mod;
            }
            x = tr[x].nxt[bitv ^ bitk];
            if (!x)
                return res;
        }
        res = (res + tr[x].val) % mod;
        return res;
    }
};

int tot = 0;

void solve() {
    long long res = 0;
    cin >> n >> k;
    Trie *trie = new Trie(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        res = (res + trie->query(a[i]) * ksm(2, i) % mod) % mod;
        trie->insert(a[i], i);
    }
    cout << (res + n) % mod << '\n';
    free(trie);
}

int main() {
    cout.tie(0), cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}