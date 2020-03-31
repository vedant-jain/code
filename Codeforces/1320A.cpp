// https://codeforces.com/problemset/problem/1320/A

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define ll long long int

int main() {

    ll count;
    cin >> count;
    vector <ll> city;
    city.resize(count);

    // DP solution

    // for (ll i = 0; i < count; i++) {
    //     cin >> city[i];
    // }

    // vector <ll> beautyDP;
    // beautyDP.resize(count);
    // beautyDP[0] = city[0]; 
    // for (ll i = 1; i < count; i++) {
    //     beautyDP[i] = city[i];
    //     for (ll j = 0; j < i; j++) {
    //         if (((city[i] - city[j]) == (i - j)) && beautyDP[i] < beautyDP[j] + city[i]) {
    //             beautyDP[i] = beautyDP[j] + city[i];
    //         }
    //     }
    // }

    // cout << beautyDP[max_element(beautyDP.begin(), beautyDP.end()) - beautyDP.begin()] << "\n";

    // new

    vector <ll> value;
    value.resize(600001);
    value.assign(600001, 0);
    for (ll i = 0; i < count; i++) {
        cin >> city[i];
        value[city[i] - i + 200000] += city[i];
    }

    cout << value[max_element(value.begin(), value.end()) - value.begin()] << "\n";



}