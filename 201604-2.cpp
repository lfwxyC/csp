#include <bits/stdc++.h>
using namespace std;

int a[16][11], b[5][5];
int start;

bool check(int row) {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (a[row][j + start] & b[i][j])
                return false;
        }
        row++;
    }
    return true;
}

int main() {
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> a[i][j];
        }
    }

    int bottom = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> b[i][j];
            if (b[i][j]) {
                bottom = i;
            }
        }
    }

    if ((bottom != 4) && (bottom != 0)) {
        for (int i = bottom; i >= 1; i--) {
            for (int j = 1; j <= 4; j++) {
                b[i - bottom + 4][j] = b[i][j];
                b[i][j] = 0;
            }
        }
    }

    cin >> start;
    start--;

    for (int row = 1; row <= 12; row++) {
        if (!check(row)) {
            row--;
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= 4; j++) {
                    if (b[i][j])
                        a[row][j + start] = 1;
                }
                row++;
            }
            break;
        }

        if (row == 12) {
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= 4; j++) {
                    if (b[i][j])
                        a[row][j + start] = 1;
                }
                row++;
            }
            break;
        }
    }

    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}