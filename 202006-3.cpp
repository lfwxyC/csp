#include <bits/stdc++.h>
using namespace std;

int w, ans = 0;
string str, line = "";
bool isList = false, isPara = false;

bool isBlank() {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '') return false;
    }
    return true;
}

int check_type() {
    if (isBlank()) return 0;

    if (str.length() >= 2) {
        if (str[0] == '*' && str[1] == ' ') return 1;

        if (isList && str[0] == ' ' && str[1] == ' ') return 1;
    }
    return 2;
}

string handle_str() {

}

void render() {

}

int main() {
    cin >> w;

    while (getline(cin, str)) {
        int type = check_type();

        switch (type) {
            case 0: // 空白行
                if (line != "") {
                    render();
                    line = "";
                    isList = false;
                }
                break;
            case 1: // 项目
                if (isPara) {
                    render();
                    line = "";
                    isPara = false;
                }

                if (!isList) {
                    isList = true;
                }
                line += handle_str();
                break;
            case 2: // 段落
                if (isList) {
                    render();
                    line = "";
                    isList = false;
                }

                if (!isPara) {
                    isPara = true;
                }
                line += handle_str();
        }
    }

    if (line != "") {
        render();
    }
    cout << ans;
    return 0;
}