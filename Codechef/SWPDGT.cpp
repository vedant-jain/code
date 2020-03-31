// codechef SWPDGT

#include <iostream>
#include <vector>
#include "bits/stdc++.h"

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int digitise(vector<int> &digits, int a) {

    int count = 0;
    int n = a;

    while (n != 0)
    {
        n /= 10;
        count++;
    }

    digits.resize(count);

    if (count!=0){
        count = 0;    
        n = a;

        while (n != 0){
            digits[count] = n % 10;
            n /= 10;
            count++;
        }
    }

    return count;

}

void calc() {
    int a, b, countA, countB, maxIndex;
    cin >> a >> b;

    vector <int> digitsA, digitsB;

    if (b > a) {
        swap(&a, &b);
    }

    countA = digitise(digitsA, a);
    countB = digitise(digitsB, b);
    maxIndex = max_element(digitsB.begin(), digitsB.end()) - digitsB.begin();
    // cout << "\n" << maxIndex;
    for (int i = countA-1; i >= 0; i--) {
        
        if (digitsA[i] < digitsB[maxIndex]) {
            swap(&digitsA[i], &digitsB[maxIndex]);
            break;
        }
    }

    int totalA = 0, totalB = 0;

    for (int i = countA-1; i >= 0; i--) {
        totalA = (totalA*10) + digitsA[i];
    }

    for (int i = countA-1; i >= 0; i--) {
        totalB = (totalB*10) + digitsB[i];
    }

    cout << totalA + totalB << "\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        calc();
    }
}