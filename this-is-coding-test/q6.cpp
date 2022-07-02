// 프로그래머스
// https://programmers.co.kr/learn/courses/30/lessons/42891

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int solution(vector<int> food_times, long long k) {
    int size = food_times.size();

    ll sum = 0;
    for (int i = 0; i < size; i++) {
        sum += food_times[i];
    }

    if (k >= sum) {
        return -1;
    }

    vector<int> sorted_times(food_times);

    sort(sorted_times.begin(), sorted_times.end());

    ll curr = 0;
    ll cnt = 0;

    ll block_left = -1;

    for (ll i = 0; i < size; i++) {
        if (curr == sorted_times[i]) {
            cnt++;
        } else {
            ll block = (size - i) * (sorted_times[i] - curr);

            if (k >= block) {
                k -= block;
            } else {
                block_left = (size - i);
                break;
            }

            curr = sorted_times[i];
            cnt = 0;
        }
    }

    ll height_diff = k / block_left;
    curr += height_diff;
    k -= height_diff * block_left;

    for (int i = 0; i < size; i++) {
        if (food_times[i] > curr) {
            if (k == 0) {
                return i + 1;
            }

            k--;
        }
    }

    return -1;
}

int main() {
    int result;

    result = solution({6, 1, 2, 4, 2, 1}, 1);
    printf("%d\n", result);

    result = solution({6, 1, 2, 4, 2, 1}, 4);
    printf("%d\n", result);

    result = solution({6, 1, 2, 4, 2, 1}, 6);
    printf("%d\n", result);

    result = solution({6, 1, 2, 4, 2, 1}, 10);
    printf("%d\n", result);

    result = solution({6, 1, 2, 4, 2, 1}, 13);
    printf("%d\n", result);

    result = solution({6, 1, 2, 4, 2, 1}, 15);
    printf("%d\n", result);

    result = solution({6, 1, 2, 4, 2, 1}, 16);
    printf("%d\n", result);

    result = solution({6, 1, 2, 4, 2, 1}, 17);
    printf("%d\n", result);

    result = solution({100000000}, 17);
    printf("%d\n", result);

    result = solution({100000000}, 99999999);
    printf("%d\n", result);

    result = solution({100000000}, 100000000);
    printf("%d\n", result);

    result = solution({100000000}, 20000000000000L);
    printf("%d\n", result);

    vector<int> times(200000, 100000000);
    for (int i=0; i<200000; i++) {
        times[i] = i+1;
    }
    result = solution(times, 20000099997L);
    printf("%d\n", result);

    return 0;
}
