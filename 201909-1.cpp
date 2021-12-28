#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
int b[N];

int main() {
    cin >> n >> m;
    memset(b, 0, sizeof(b));
    int max_num = 0, k = 1, t = 0;

    for (int i = 1; i <= n; i++) {
        int y;
        cin >> y;

        t += y;
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;

            b[i] -= x;
            t += x;
        }

        if (max_num < b[i]) {
            max_num = b[i];
            k = i;
        }
    }

    cout << t << " " << k << " " << b[k] << endl;
    return 0;
}