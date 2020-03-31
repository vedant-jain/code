// https://codeforces.com/problemset/problem/1328/B

#include <iostream>
#include <math.h>
using namespace std;

#define ll long long int

void calc() {
    ll n, k;
    cin >> n >> k;

    k--;

    ll first, second;

    first = floor(
        (double) (1 + sqrt(1 + 4*(2 * k))) / (double) 2
    );

    second = k - (first*(first-1)/2);

    first = n - first - 1;
    second = n - second - 1;

    for (ll i = 0; i < n; i++) {
        if (i != first && i != second) {
            cout << "a";
        }
        else {
            cout << "b";
        }
    }
    cout << "\n";
}

int main() {
    ll loops;
    cin >> loops;
    while (loops--) {
        calc();
    }
}