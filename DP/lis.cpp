#include<iostream>
using namespace std;

int count(int arr[], int length) {
    int max = arr[0];
    int a[length];
    a[0] = 1;

    for (int i = 1; i < length; i++) {
        if (max <= arr[i]) {
            a[i] = a[i-1] + 1;
            max = arr[i];
        }
        else {
            a[i] = a[i-1];
        }
    }

    return a[length-1];
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int length = sizeof(arr)/sizeof(int);
    cout << count(arr, length) << "\n";
    return 0;
}