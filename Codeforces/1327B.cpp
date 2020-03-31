// https://codeforces.com/contest/1327/problem/B

#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

void calc() {
    ll n, count, prince;
    cin >> n;

    vector <int> princes, unmarried;

    princes.assign(100001, 1);
    unmarried.assign(100001, 1);

    for (ll i = 1; i <= n; i++) {
        cin >> count;

        for (ll j = 1; j <= count; j++) {
            cin >> prince;

            if ((princes[prince] == 1) && (unmarried[i] == 1)) {
                princes[prince] = 0;
                unmarried[i] = 0;
            }
        }

    }

    for (ll i = 1; i <= n; i++) {
        if (unmarried[i] == 1) {
            printf("IMPROVE\n");
            for (ll j = 1; j <= n; j++) {
                if (princes[j] == 1) {
                    printf("%lld %lld\n", i, j);
                    return;
                }
            }
        }
    }

    printf("OPTIMAL\n");

}

int main() {
    ll loops;
    cin >> loops;

    while (loops--) {
        calc();
    }

    return 0;
}