// https://codeforces.com/problemset/problem/1324/D

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define ll long long int

int main () {

    ll topics;

    vector <long long int> a, b;
    a.assign(200001, 0);
    b.assign(200001, 0);

    ll total = 0;

    cin >> topics;

    a.resize(topics);
    b.resize(topics);

    for (ll i = 0; i < topics; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < topics; i++) {
        cin >> b[i];
    }

    for (ll i = 0; i < topics; i++) {
        a[i] -= b[i];
    }

    sort(a.begin(), a.end());

    for (ll i = 0; i < topics; i++) {

        ll j = lower_bound(a.begin(), a.end(), -a[i] + 1) - a.begin();
        // printf("index at %lld for i = %lld\n", j, i);
        total += topics - ((j > i) ? j : i);
        if (a[i] > 0) total--;
    }

    printf("%lld", total);

}