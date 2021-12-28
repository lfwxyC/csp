#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int r, y, g, n;
    cin >> r >> y >> g >> n;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int k, t;
        cin >> k >> t;

        int s = (ans - t) % (r + y + g);
        switch (k) {
            case 0:
                ans += t;
                break;
            case 1:
                if (ans < t) {
                    ans = t;
                } else {
                    if (s >= g) {
                        ans += r + y + g - s;
                    }
                }
                break;
            case 2:
                if (ans < t) {
                    ans = t + r;
                } else {
                    if (s < r) {
                        ans += r - s;
                    } else if (s >= r + g) {
                        ans += 2 * r + g + y - s;
                    }
                }
                break;
            case 3:
                if (ans >= t) {
                    if (s < r + y) {
                        ans += r + y - s;
                    }
                }
                break;
        }
    }

    cout << ans;
    return 0;
}