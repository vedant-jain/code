// https://codeforces.com/problemset/problem/1343/C

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

typedef struct linkedList {
    ll max;
    struct linkedList *next;
} linkedList;

linkedList * newList(ll num) {
    linkedList *temp = (linkedList *) malloc(sizeof(linkedList));
    temp->max = num;
    temp->next = NULL;
    return temp;
}

ll calc() {

    ll n;
    cin >> n;

    ll sum = 0;

    vector<ll> input;
    input.resize(n);

    for (ll i = 0; i < n; i++) {
        cin >> input[i];
    }

    linkedList *temp = newList(input[0]);
    linkedList *start = temp;

    for (ll i = 1; i < n; i++) {
        if ((input[i]>0) == (input[i-1]>0)) {
            if (temp->max < input[i]) {
                temp->max = input[i];
            }
        }
        else {
            temp->next = newList(input[i]);
            temp = temp->next;
        }
    }

    while (start != NULL) {
        sum += start->max;
        start = start->next;
    }
    return sum;
}

int main() {
    ll tests;
    cin >> tests;
    while (tests--) {
        cout << calc() << endl;
    }
}