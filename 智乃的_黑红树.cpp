#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
    int l, r;
} tr[N];
int b, r, tot;

void init() {
    for (int i = 0; i <= tot; i++) {
        tr[i].l = tr[i].r = 0;
    }
    tot = 1;
    return;
}

void solve() {
    init();
    int curb = 1, curr = 0;
    cin >> b >> r;
    queue<int> bq, rq;
    bq.push(1);
    while (curb < b || curr < r) {
        if (curb < b) {             // 加黑点，找可用的红点
            if (rq.empty()) {       // 如果没有可用的红点
                int x = bq.front(); // 从已有的黑点里生成两个红点
                bq.pop();
                tr[x].l = ++tot, tr[x].r = ++tot;
                rq.push(tr[x].l), rq.push(tr[x].r);
                curr += 2;
            }
            int x = rq.front();
            rq.pop();
            tr[x].l = ++tot, tr[x].r = ++tot;
            bq.push(tr[x].l), bq.push(tr[x].r);
            curb += 2;
        }
        if (curr < r) {             // 加红点
            if (bq.empty()) {       // 如果没有可用的黑点
                int x = rq.front(); // 从已有的红点里生成两个黑点
                rq.pop();
                tr[x].l = ++tot, tr[x].r = ++tot;
                bq.push(tr[x].l), bq.push(tr[x].r);
                curb += 2;
            }
            int x = bq.front();
            bq.pop();
            tr[x].l = ++tot, tr[x].r = ++tot;
            rq.push(tr[x].l), rq.push(tr[x].r);
            curr += 2;
        }
    }
    if (curr == r && curb == b) {
        cout << "Yes\n";
        for (int i = 1; i <= tot; i++) {
            cout << (tr[i].l == 0 ? -1 : tr[i].l) << " " << (tr[i].r == 0 ? -1 : tr[i].r) << "\n";
        }
    } else {
        cout << "No\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}