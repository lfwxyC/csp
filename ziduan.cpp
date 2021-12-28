#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const int inf = -1e9;
int a[maxn], dp[maxn];

int main() {
    int n;
    cin >> n;

    int ans = inf;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);
    return 0;
}