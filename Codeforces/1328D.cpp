// https://codeforces.com/problemset/problem/1328/D

#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

ll toggle(ll *key) {
    if (*key == 1) {
        *key = 2;
        return 1;
    }
    else {
        *key = 1;
        return 2;
    }
    return 1;
}

void calc() {
    // mul = 0 -> all same elements; print 1
    ll n, key = 1, repeated = 0, multiple = 0, required = 1;
    vector <int> input;
    vector<ll> output;

    cin >> n;
    
    input.resize(n);
    output.resize(n);
    output.assign(n, 1);

    for (ll i = 0; i < n; i++) {
        cin >> input[i];
        if (input[i] != input[i-1] && i > 0) {
            multiple = 1;
        }
    }
    
    if (multiple == 0) {
        cout << "1\n";
        for (ll i = 0; i < n; i++) {
            cout << key << " ";
        }
        cout << "\n";
        return;
    }

    required = 2; 
    output[0] = toggle(&key);
    for (ll i = 1; i < n; i++){

        if (n % 2 == 0) {
            output[i] = toggle(&key);
            continue;
        }
        else {
            if (input[i] == input[i-1] && repeated == 0) {
                toggle(&key);
                output[i] = toggle(&key);
                repeated = 1;
                continue;
            }
            if (i == n-1 && repeated == 0) {
                if (input[0] == input[n-1]) {
                    output[i] = 1;
                    break;
                }
                output[i] = 3;
                required = 3;
                break;
            }
            output[i] = toggle(&key);
        }
        
    }

    cout << required << "\n";

    for (ll i = 0; i < n; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";
    return;
}

int main() {
    ll loops;
    cin >> loops;
    while (loops--) {
        calc();
    }
}