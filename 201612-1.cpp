#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int a[maxn];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        int small = 0, big = 0;

        for (int j = 1; j <= n; j++) {
            if (a[j] < a[i]) {
                small++;
            } else if (a[j] > a[i]) {
                big++;
            }
        }

        if (small == big) {
            cout << a[i];
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << -1;
    }

    return 0;
}