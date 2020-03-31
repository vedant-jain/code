// https://codeforces.com/contest/1324/problem/A

#include <stdio.h>
#include <stdlib.h>

void calc() {
    int columns, minimum = 101;
    scanf("%d", &columns);
    int height[columns];
    for (int i = 0; i < columns; i++) {
        scanf("%d", &height[i]);
        if (height[i] < minimum) {
            minimum = height[i];
        }
    }

    for (int i = 0; i < columns; i++) {
        height[i] -= minimum;
        if (height[i] % 2 == 1) {
            // no
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
    return;
}

int main() {

    int loop;
    scanf("%d", &loop);

    int columns, minimum = 101;

    while (loop--) {
        calc();
    }

}