#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1010, M = 1e5 + 5;
const int q = 1e9 + 7;
int n;
int obstacle[N];
ll f[N][N], sum[N][N];
bool vis[M];
vector<int> yinzi[M];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> obstacle[i];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 2 * i; j <M; j += i) {
            yinzi[j].emplace_back(i);
        }
    }

    for (int i = 2; i <= n; i++) {
        memset(vis, 0, sizeof (vis));

        for (int j = i - 1; j > 0; j--) {
            int len = obstacle[i] - obstacle[j];
            f[j][i - 1] = 0;

            for (auto x:yinzi[len]) {
                if (!vis[x]) {
                    f[j][i - 1]++;
                    vis[x] = 1;
                }
            }
            vis[len] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum[i][j] = f[i][j];
        }
    }

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int l = i, r = i + len - 1;

            for (int k = l; k < r; k++) {
                sum[l][r] += f[l][k] * sum[k + 1][r];
                sum[l][r] %= q;
            }
        }
    }

    int ans = sum[1][n - 1] % q;
    printf("%d", ans);
    return 0;
}