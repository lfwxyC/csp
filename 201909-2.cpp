#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, x;
int t, d, e;
int a[N], b[N];

int main() {
    cin >> n;

    t = d = e = 0;
    memset(b, 0, sizeof (b));

    for (int i = 1; i <= n; i++) {
        cin >> m >> a[i];

        for (int j = 1; j < m; j++) {
            cin >> x;

            if (x > 0 && a[i] > x) {
                a[i] = x;
                if (b[i] == 0) {
                    d++;
                    b[i] = 1;
                }
            }
            if (x < 0) {
                a[i] += x;
            }
        }

        t += a[i];
        if (i > 2) {
            if (b[i] && b[i - 1] && b[i - 2]) e++;
        }
    }

    if (b[n - 1] && b[n] && b[1]) e++;
    if (b[n] && b[1] && b[2]) e++;

    cout << t << " " << d << " " << e << endl;
    return 0;
}