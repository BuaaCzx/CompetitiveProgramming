#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, a[maxn], d[maxn], vis[maxn];
struct node {
    int pre, nxt;
} lis[maxn];
void solve() {
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n + 1; i++)
        vis[i] = a[i] = d[i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++) {
        lis[i] = {i - 1, i + 1};
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    while (!s.empty()) {
        cnt++;
        set<int> tmp;
        vector<int> del;
        for (int i : s) { // 确立死亡
            if (a[lis[i].pre] + a[lis[i].nxt] > d[i]) {
                del.push_back(i);
                vis[i] = 1;
            }
        }
        for (int i : del) { // 更新链表，计算可能死亡
            lis[lis[i].pre].nxt = lis[i].nxt;
            lis[lis[i].nxt].pre = lis[i].pre;
            if (!vis[lis[i].pre] && lis[i].pre != 0)
                tmp.insert(lis[i].pre);
            if (!vis[lis[i].nxt] && lis[i].nxt != n + 1)
                tmp.insert(lis[i].nxt);
        }
        s = tmp;
        cout << del.size() << ' ';
    }
    for (int i = cnt; i < n; i++) {
        cout << "0 ";
    }
    cout << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}