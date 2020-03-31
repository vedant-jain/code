// https://codeforces.com/problemset/problem/1315/B

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define ll long long int

void calc() {

    ll a, b, p;
    cin >> a >> b >> p;

    string s;
    cin >> s;

    ll length = s.length();

    if (p < a && p < b) {
        printf("%lld\n", length);
        return;
    }

    if (s[length-1] == s[length-2]) {
        if (p >= ((s[length-1] == 'A') ? a : b))
            p -= ((s[length-1] == 'A') ? a : b);
        else {
            printf("%lld\n", length);
            return;
        }
    }

    for (ll i = length - 1; i >= 0; i--) {
        if (s[i-1] != s[i]) {
            if (p >= ((s[i-1] == 'A') ? a : b)) {
                p -= ((s[i-1] == 'A') ? a : b);
                // printf("Buying ticket at %lld; remaining p = %lld\n", i-1, p);
            }
            else {
                printf("%lld\n", i+1);
                return;
            }
        }
    }


    printf("1\n");
    
}

int main() {
    ll loops;
    cin >> loops;

    while (loops--) {calc();}
}