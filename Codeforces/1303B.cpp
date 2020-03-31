// https://codeforces.com/problemset/problem/1303/B

#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;

void calc() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (n < a) {
        cout << n << "\n";
        return;
    }
    n = ceil((double)n/(double)2);
    ll days = 0;
    while (n > 0) {
        n -= a;
        days += ((n < 0) ? (a + n) : a);
        if (n > 0) {
            days += b;
        }
    }
    cout << days << "\n";
}

int main() {
    ll loop;
    cin >> loop;
    while (loop--) {
        calc();
    }
}