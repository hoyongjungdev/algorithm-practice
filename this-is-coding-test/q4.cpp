#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int arr[1005];

int main() {
    int n;
    scanf("%d", &n);

    int num;
    for (int i=0; i<n; i++) {
        scanf("%d", &num);
        arr[i] = num;
    }

    sort(arr, arr + n);

    if (arr[0] != 1) {
        printf("1\n");
        return 0;
    }

    int max_val = 1;

    for (int i=1; i<n; i++) {
        if (arr[i] >= max_val + 2) {
            printf("%d\n", max_val + 1);
            return 0;
        }

        max_val += arr[i];
    }

    printf("%d\n", max_val + 1);

    return 0;
}
