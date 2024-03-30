#include <bits/stdc++.h>
using namespace std;
// 三元组

set<tuple<string, string, string>> st;
int main() {
    freopen("test.txt", "r", stdin);
    string h, r, t;
    while (cin >> h >> r >> t) {
        if (st.count({h, r, t}) == 1) {
            cout << "error!!!\n";
        }
        st.insert({h, r, t});
    }
    return 0;
}