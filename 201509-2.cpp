#include <bits/stdc++.h>
using namespace std;

int y, d;
int month_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    cin >> y >> d;

    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        month_day[1] = 29;

    for (int i = 0; i < 12; i++) {
        if (d <= month_day[i]) {
            cout << i + 1 << "\n" << d;
            break;
        }
        d -= month_day[i];
    }
    return 0;
}