#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int n, ans;
int vis[maxn];
vector<int> location[maxn];

int main() {
    int a, cnt = 1;
    bool flag = true;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        location[a].emplace_back(i);

        if (a) flag = false;
    }

    ans = 1;
    memset(vis, 0, sizeof (vis));
    vis[0] = vis[n + 1] = 1;

    for (int i = 0; i < maxn; i++) {
        for (auto l:location[i]) {
            vis[l] = 1;
            if (vis[l - 1] && vis[l + 1]) cnt--;
            else if ((vis[l - 1] == 0) && (vis[l + 1] == 0)) cnt++;
        }
        ans = max(ans, cnt);
    }
    if (flag) ans = 0;
    cout << ans;
    return 0;
}