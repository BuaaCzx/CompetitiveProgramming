#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int n, k, a[maxN];
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && a[q.back()] < a[i]) {
            q.pop_back();
        }
        while (!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        q.push_back(i);
        if (i >= k - 1) {
            cout << a[q.front()] << endl;
        }
    }
}
int main() {
    solve();
    return 0;
}