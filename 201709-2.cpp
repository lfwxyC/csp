#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int N, K, w, s, c;
int a[maxn];
struct Teacher{
    int id, time, type;
}G[maxn << 1];

bool cmp(const Teacher &t1, const Teacher &t2) {
    if (t1.time != t2.time) return t1.time < t2.time;
    if (t1.type != t2.type) return t1.type > t2.type;
    return t1.id < t2.id;
}

int main() {
    cin >> N >> K;

    int cnt = 1;
    for (int i = 1; i <= K; i++) {
        cin >> w >> s >> c;

        G[cnt].id = w, G[cnt].time = s, G[cnt].type = 0;
        cnt++;
        G[cnt].id = w, G[cnt].time = s + c, G[cnt].type = 1;
        cnt++;
    }

    for (int i = 1; i <= N; i++) {
        a[i] = i;
    }

    sort(G, G + cnt, cmp);
    for (int i = 1; i < cnt; i++) {
        Teacher t = G[i];

        if (t.type == 0) {
            for (int i = 1; i <= N; i++) {
                if (a[i] == t.id) {
                    a[i] = -1;
                    break;
                }
            }
        } else {
            for (int i = 1; i <= N; i++) {
                if (a[i] == -1) {
                    a[i] = t.id;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}