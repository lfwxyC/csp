#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int n, lx, ly, rx, ry, ans;
int a[maxn][maxn];

int main() {
    cin >> n;

    ans = 0;
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; i++) {
        cin >> lx >> ly >> rx >> ry;

        for (int j = lx + 1; j <= rx; j++) {
            for (int k = ly + 1; k <= ry; k++) {
                if (a[j][k] == 0) {
                    a[j][k] = 1;
                    ans++;
                }
            }
        }
    }

    cout << ans;
    return 0;
}