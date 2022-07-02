#include <iostream>
#include <cstdio>

using namespace std;

int arr[100005];

int main() {
    int n;
    scanf("%d", &n);

    int num;
    for (int i=0; i<n; i++) {
        scanf("%d", &num);
        arr[i] = num;
    }

    sort(arr, arr + n);

    int cnt = 0;
    int result = 0;

    for (int i=0; i<n; i++) {
        cnt++;
        if (arr[i] <= cnt) {
            result++;
            cnt = 0;
        }
    }

    printf("%d\n", result);

    return 0;
}
