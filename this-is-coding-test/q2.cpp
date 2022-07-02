#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int arr[25];

int main() {
    string s;
    cin >> s;

    int size = s.size();

    for (int i=0; i<size; i++) {
        arr[i] = s[i] - '0';
    }

    int result = arr[0];

    for (int i=1; i<size; i++) {
        result = max(result + arr[i], result * arr[i]);
    }

    printf("%d\n", result);

    return 0;
}
