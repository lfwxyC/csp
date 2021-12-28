#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        stack<int> num_st;
        stack<char> alg_st;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                if (!alg_st.empty() && alg_st.top() != '+') {
                    if (alg_st.top() == 'x' || alg_st.top() == '/') {
                        int op1 = num_st.top();
                        num_st.pop();
                        int op2 = s[i] - '0';

                        int op;
                        if (alg_st.top() == 'x') {
                            op = op1 * op2;
                        } else {
                            op = op1 / op2;
                        }

                        num_st.push(op);
                        alg_st.pop();
                    }
                    else if (alg_st.top() == '-') {
                        int op = s[i] - '0';
                        num_st.push(-op);
                        alg_st.pop();
                    }
                } else {
                    int op = s[i] - '0';
                    num_st.push(op);
                }
            } else {
                alg_st.push(s[i]);
            }
        }

        int ans = 0;
        while (!num_st.empty()) {
            int op = num_st.top();
            num_st.pop();

            ans += op;
        }

        if (ans == 24) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}