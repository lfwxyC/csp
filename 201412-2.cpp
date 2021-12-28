#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
int n;
int a[maxn][maxn];

void dfs(int row, int col, int dir) {
    cout << a[row][col] << " ";

    if (row == n && col == n) return;

    if (dir == 1) {
        if (row + 1 > n)
            dfs(row, col + 1, -1);
        else if (col - 1 <= 0)
            dfs(row + 1, col, -1);
        else
            dfs(row + 1, col - 1, 1);
    } else {
        if (col + 1 > n)
            dfs(row + 1, col, 1);
        else if (row - 1 <= 0)
            dfs(row, col + 1, 1);
        else
            dfs(row - 1, col + 1, -1);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    dfs(1, 1, -1);
    return 0;
}