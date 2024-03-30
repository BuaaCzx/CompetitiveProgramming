#include <bits/stdc++.h>
using namespace std;
#define mi(x, y) ((x) < (y) ? x : y)
const int inf = 0x7fffffff, maxN = 2e5 + 5;
int a, b, n, m[1005][1005], maxx[1005][1005], minn[1005][1005], res = inf; // 表示第i行第j列往左n个数的最大最小值
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= a; i++) {
        deque<int> qmax, qmin;
        for (int j = 1; j <= b; j++) {
            while (!qmax.empty() && m[i][j] >= m[i][qmax.back()]) {
                qmax.pop_back();
            }
            while (!qmax.empty() && qmax.front() <= j - n) {
                qmax.pop_front();
            }
            qmax.push_back(j);
            maxx[i][j] = m[i][qmax.front()];
            while (!qmin.empty() && m[i][j] <= m[i][qmin.back()]) {
                qmin.pop_back();
            }
            while (!qmin.empty() && qmin.front() <= j - n) {
                qmin.pop_front();
            }
            qmin.push_back(j);
            minn[i][j] = m[i][qmin.front()];
        }
    }
    for (int j = n; j <= b; j++) {
        deque<int> qmax, qmin;
        for (int i = 1; i <= a; i++) {
            while (!qmax.empty() && maxx[i][j] >= maxx[qmax.back()][j]) {
                qmax.pop_back();
            }
            while (!qmax.empty() && qmax.front() <= i - n) {
                qmax.pop_front();
            }
            qmax.push_back(i);
            while (!qmin.empty() && minn[i][j] <= minn[qmin.back()][j]) {
                qmin.pop_back();
            }
            while (!qmin.empty() && qmin.front() <= i - n) {
                qmin.pop_front();
            }
            qmin.push_back(i);
            if (i >= n)
                res = mi(res, maxx[qmax.front()][j] - minn[qmin.front()][j]);
        }
    }
    cout << res;
    return 0;
}