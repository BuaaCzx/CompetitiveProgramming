#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int maxn = 3e5 + 5;
int a[maxn], l[maxn], r[maxn];
set<pii> s;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> a[i];
    }
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty()) {
            l[i] = st.top();
        } else {
            l[i] = 0;
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty()) {
            r[i] = st.top();
        } else {
            r[i] = n + 1;
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        s.insert({l[i], r[i]});
    }
    cout << s.size() << "\n";
    return 0;
}