#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int maxL = 1010;
int n, L, t;
int a[maxn], dir[maxn], vis[maxL];

int main() {
    cin >> n >> L >> t;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dir[i] = 1;
    }

    for (int i = 1; i <= t; i++) {
        memset(vis, 0, sizeof (vis));

        for (int j = 1; j <= n; j++) {
            a[j] += dir[j];
            vis[a[j]]++;

            if (a[j] >= L || a[j] <= 0) {
                dir[j] *= -1;
            }
        }

        for (int j = 1; j <= n; j++) {
            if (vis[a[j]] > 1) {
                dir[j] *= -1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}