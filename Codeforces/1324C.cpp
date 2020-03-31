// https://codeforces.com/contest/1324/problem/C

#include <iostream>
#include <string.h>
using namespace std;
#define ll long long int

ll calcMin() {
    string input;
    getline(cin, input);
    ll len = input.length();
    ll jump = 0;
    ll low = 0, mid, high = len + 1;
    ll dp[len+2] = {0};

    while (low < high) {
        mid = (low + high) / 2;
        for (ll i = mid; i > 0; i--) {
            if (input[i] == 'R') {
                dp[i] = 1;
            }
        }
    }
}

int main() {
    ll loops;

    while(loops--) {
        calcMin();
    }
}