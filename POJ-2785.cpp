#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 4010;
int a[N], b[N], c[N], d[N];
vector<int> x, y;

int check(int sum) {
    int lo = 0, hi = y.size() - 1;

    while (lo <= hi) {
        int mid = lo + hi >> 1;

        if (sum + y[mid] == 0) {
            int k = mid + 1, ans = 1;
            while (sum + y[k] == 0 && k < y.size()) {
                ans++, k++;
            }

            k = mid - 1;
            while (sum + y[k] == 0 && k >= 0) {
                ans++, k--;
            }
            return ans;
        }

        if (sum + y[mid] < 0) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            x.push_back(a[i] + b[j]);
            y.push_back(c[i] + d[j]);
        }
    }
    sort(y.begin(), y.end());

    int cnt = 0;
    for (int i = 0; i < x.size(); i++) {
        cnt += check(x[i]);
    }

    printf("%d", cnt);
    return 0;
}