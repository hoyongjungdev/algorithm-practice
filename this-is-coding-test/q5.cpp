#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int arr[1005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        arr[i] = num;
    }

    int result = n * (n - 1) / 2;

    sort(arr, arr + n);

    int before = arr[0];
    int cnt = 1;

    for (int i=1; i<n; i++) {
        if (before == arr[i]) {
            cnt++;
        } else {
            result -= cnt * (cnt-1) / 2;
            before = arr[i];
            cnt = 1;
        }
    }

    result -= cnt * (cnt-1) / 2;

    printf("%d\n", result);

    return 0;
}
