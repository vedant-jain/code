#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int subCalc() {
    int n, x;
    cin >> n >> x;
    vector<int> arr;
    arr.resize(n);
    int total = 0;
    int a = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    int l = 0, r = n;

    while (l < r) {
        if (total % x != 0) {
            return n;
        }
        for (int a = 0; a < n; a++) {
            if (arr[l + a] % x != 0) {
                for (int i = 0; i <= a; i++) {
                    total -= arr[l+i];
                }
                n -= a+1;
                l += a;
                break;
            }
            else if (arr[r - a] % x != 0) {
                for (int i = 0; i <= a; i++) {
                    total -= arr[r-i];
                }
                n -= a+1;
                r -= a;
                break;
            }
        }
        if (a == n-1) {
            return -1;
        }
    }

    if (l > r) {
        return -1;
    }
    return n;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cout << subCalc() << endl;
    }
}