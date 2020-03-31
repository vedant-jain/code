// https://codeforces.com/contest/1324/problem/B

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(int *input, int len) {
    // make second array which is reverse of input
    int *rev = (int *)malloc(sizeof(int)*len);
    for (int i = 0; i < len; i++) {
        *(rev+i) = *(input + len - 1 - i);
    }

    // find common subsequence
    int sub[len+1][len+1];

    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            if (i == 0 || j == 0)
                sub[i][j] = 0;

            else if (*(input + i - 1) == *(rev + j - 1))
                sub[i][j] = sub[i-1][j-1] + 1; 

            else
                sub[i][j] = max(sub[i-1][j], sub[i][j-1]);
        }
    }

    return sub[len][len];

}

int main() {
    int loops, len;
    scanf("%d", &loops);
    while(loops--) {
        scanf("%d", &len);
        int *input = (int *)malloc(sizeof(int)*len);
        for (int i = 0; i < len; i++) {
            scanf("%d", (input + i));
        }
        printf((lcs(input, len) > 2) ? "YES\n" : "NO\n");
    }
}