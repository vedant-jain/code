// https://codeforces.com/contest/1327/problem/A

#include <iostream>
using namespace std;
#define ll long long int

void calc() {
    ll n, k;
    cin >> n >> k;
    k = k*k;

    if (((n-k)%2 == 0) && (k <= n)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main() {
    ll loops;
    cin >> loops;

    while (loops--) {
        calc();
    }
}