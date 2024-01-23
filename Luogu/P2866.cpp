#include <bits/stdc++.h>
using namespace std;
const int maxN = 8e4 + 5;
int n, a[maxN];
long long res;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        if (st.empty()) {
            res += n - 1 - i;
        } else {
            res += st.top() - i - 1;
        }
        st.push(i);
    }
    cout << res;
    return 0;
}