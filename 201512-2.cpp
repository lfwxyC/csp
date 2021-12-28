#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;
int n, m;
int a[maxn][maxn];

struct row_position{
    int row, start_col, end_col;
};
vector<row_position> rv;

struct col_position{
    int col, start_row, end_row;
};
vector<col_position> cv;

bool check_row(int row, int col) {
    if ((a[row][col] == a[row][col + 1]) && (a[row][col] == a[row][col + 2]))
        return true;
    return false;
}

bool check_col(int row,int col) {
    if ((a[row][col] == a[row + 1][col]) && (a[row][col] == a[row + 2][col]))
        return true;
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int k;
    row_position rp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 2; j++) {
            if (check_row(i, j)) {
                k = j;
                while ((k <= m) && (a[i][j] == a[i][k])) k++;

                rp.row = i, rp.start_col = j, rp.end_col = k;
                rv.emplace_back(rp);
            }
        }
    }

    col_position cp;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n - 2; i++) {
            if (check_col(i, j)) {
                k = i;
                while ((k <= n) && (a[i][j] == a[k][j])) k++;

                cp.col = j, cp.start_row = i, cp.end_row = k;
                cv.emplace_back(cp);
            }
        }
    }

    for (auto vv:rv) {
        for (int j = vv.start_col; j < vv.end_col; j++) {
            a[vv.row][j] = 0;
        }
    }

    for (auto vv:cv) {
        for (int i = vv.start_row; i < vv.end_row; i++) {
            a[i][vv.col] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}