#include <bits/stdc++.h>
using namespace std;

int T;
int amount[] = {0, 1500, 4500, 9000, 35000, 55000, 80000, 155000};
float rate[] = {0, 0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};

int get_tax(int A) {
    float tax = 0;

    for (int i = 1; i < 8; i++) {
        if (A <= amount[i]) {
            tax += (A - amount[i - 1]) * rate[i];
            return tax;
        }
        tax += (amount[i] - amount[i - 1]) * rate[i];
    }
    return tax;
}

int main() {
    cin >> T;

    if (T <= 3500) {
        cout << T;
        return 0;
    }

    int S = (T / 100 + 1) * 100;
    for (; S <= 151000; S += 100) {
        int tax = get_tax(S - 3500);

        if (T == S - tax) break;
    }

    cout << S;
    return 0;
}