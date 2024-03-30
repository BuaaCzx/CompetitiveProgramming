#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

void print(int x) {
    if (x == 1) {
        printf("1");
        return;
    }
    print(x - 1);
    printf(" %d ", x);
    print(x - 1);
}

void solve() {
    int n;
    scanf("%d", &n);
    print(n);
}
int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}