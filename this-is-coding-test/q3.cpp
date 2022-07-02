// 백준 1439번

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int size = s.size();

    int one = 0, zero = 0;

    char before = s[0];
    if (before == '0') {
        zero++;
    } else {
        one++;
    }

    for (int i=1; i<size; i++) {
        if (s[i] != before) {
            if (s[i] == '0') {
                zero++;
            } else {
                one++;
            }
        }

        before = s[i];
    }

    printf("%d\n", min(zero, one));

    return 0;
}
