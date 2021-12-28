#include <bits/stdc++.h>
using namespace std;

int n;

bool check(int i) {
    if (i % 7 == 0) return 1;

    while (i) {
        if (i % 10 == 7) return 1;
        i /= 10;
    }
    return 0;
}

int main() {
    cin >> n;

    int a = 0, b = 0, c = 0, d = 0, cnt = 0, i = 1;
    while (1) {
        if (cnt == n) break;

        if (check(i)) {
            switch (i % 4) {
                case 0:
                    d++;
                    break;
                case 1:
                    a++;
                    break;
                case 2:
                    b++;
                    break;
                case 3:
                    c++;
                    break;
            }
        } else
            cnt++;

        i++;
    }

    printf("%d\n%d\n%d\n%d", a, b, c, d);
    return 0;
}