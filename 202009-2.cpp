#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int main() {
    ios::sync_with_stdio(false);

    int n, k, t, a, b, c, d;
    cin >> n >> k >> t >> a >> b >> c >> d;

    int pass = 0, stay = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        bool isPass = 0, isStay = 0;

        for (int j = 0; j < t; j++) {
            int x, y;
            cin >> x >> y;

            if (x >= a && x <= c && y >= b && y <= d) {
                cnt++;
                isPass = 1;

                if (cnt >= k) {
                    isStay = 1;
                }
            }
            else {
                cnt = 0;
            }
        }

        if (isPass) {
            pass++;

            if (isStay) {
                stay++;
            }
        }
    }

    printf("%d\n%d", pass, stay);
    return 0;
}