#include <bits/stdc++.h>
using namespace std;
int tt;
string s;

struct node {
    int x, y;
}b[200005];

void solve() {
    int cnt = 0, n = s.size();
    for (int i = 1; i < n - 1; i ++)
        if (s[0] <= s[i] && s[i] <= s[n - 1] ||
            s[0] >= s[i] && s[i] >= s[n - 1])
            b[++ cnt].x = i + 1, b[cnt].y = s[i] - 'a' + 1;
    if (s[0] <= s[n - 1])
        sort(b + 1, b + 1 + cnt, [](node a, node b) {
            return a.y < b.y;
        });
    else
        sort(b + 1, b + 1 + cnt, [](node a, node b) {
            return a.y > b.y;
        });
    printf("%d %d\n", abs(s[0] - s[n - 1]), cnt + 2);
    printf("1 ");
    for (int i = 1; i <= cnt; i ++)
        printf("%d ", b[i].x);
    printf("%d\n", n);
}
int main() {
    cin >> tt;
    while (tt --) {
        cin >> s;
        solve();
    }
    return 0;
}