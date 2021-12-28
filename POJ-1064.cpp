#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, k;
int a[maxn];
bool can;

bool check(int mid) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i] / mid;
    }

    if (cnt >= k) {
        can = 1;
        return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    can = 0;

    int lo = 1, hi = 0;
    for (int i = 1; i <= n; i++) {
        float f;
        cin >> f;

        a[i] = f * 100;
        hi = max(hi, a[i]);
    }

    while (lo <= hi) {
        int mid = lo + hi >> 1;

        if (check(mid)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    if (!can) {
        hi = 0;
    }

    float ans = (float) hi / 100.0;
    printf("%.2f", ans);
    return 0;
}