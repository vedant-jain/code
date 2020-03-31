// https://codeforces.com/problemset/problem/1307/B

#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;

#define ll long long int

void calc() {
    ll count, distance, maxjump = -1;
    vector <ll> jumps;
    cin >> count >> distance;
    jumps.resize(count);
    for (ll i = 0; i < count; i++) {
        cin >> jumps[i];
        if (jumps[i] > maxjump) {
            maxjump = jumps[i];
        }
    }

    for (ll i = 0; i < count; i++) {
        if (jumps[i] > 0) {
            if (distance == jumps[i]) {
                cout << "1\n";
                return;
            }
        }
    }

    cout << (int) max((double)2, ceil((double) distance / (double) maxjump)) << "\n";
    jumps.clear();
}

int main() {
    int loops;
    cin >> loops;
    while (loops--) {calc();}
}