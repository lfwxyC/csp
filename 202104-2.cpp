#include <bits/stdc++.h>
using namespace std;

const int N = 610;
int a[N][N], b[N][N];

int main() {
    int n, L, r, t;
    cin >> n >> L >> r >> t;

    memset(b, 0, sizeof (b));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            b[i][j] = b[i][j - 1] + a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = 0, cnt = 0;

            for (int x = i - r; x <= i + r; x++) {
                if (x < 1 || x > n) continue;

                int ll = max(j - r, 1), rr = min(j + r, n);
                sum += b[x][rr] - b[x][ll - 1];
                cnt += rr - ll + 1;
            }

            if (sum <= t * cnt) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}