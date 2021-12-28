#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, p, q;
int a[maxn];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }

    while (m--) {
        cin >> p >> q;

        int i;
        for (i = 1; i <= n; i++) {
            if (a[i] == p) break;
        }

        if (q > 0) {
            for (int j = 0; j < q; j++) {
                a[i] = a[i + 1];
                i++;
            }
        } else {
            for (int j = 0; j > q; j--) {
                a[i] = a[i - 1];
                i--;
            }
        }
        a[i] = p;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}