#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll a[605][605], sum[605][605];

int main() {
    ios::sync_with_stdio(false);

    int n, l, r, t;
    cin >> n >> l >> r >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l_row = max(1, i - r), r_row = min(n, i + r);

        for (int j = 1; j <= n; j++) {
            int l_col = max(1, j - r), r_col = min(n, j + r);
            int num = (r_row - l_row + 1) * (r_col - l_col + 1);
            int avg = sum[r_row][r_col] - sum[l_row - 1][r_col] - sum[r_row][l_col - 1] + sum[l_row - 1][l_col - 1];

            if (avg <= t * num) {
                ans++;
            }
        }
    }

    printf("%lld", ans);
    return 0;
}