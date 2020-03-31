#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(char arr[], int low, int high, int pivot, int n) {
    int i = low;
    char temp;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        else if (arr[j] == pivot) {
            temp = arr[j];
            arr[j] = arr[high];
            arr[high] = temp;
            j--;
        }
    }

    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;

}

void match(char nuts[], char bolts[], int n, int low, int high) {

    if (low < high) {
        
        int pivot = partition(nuts, low, high, bolts[high], n);

        partition(bolts, low, high, nuts[pivot], n);

        match(nuts, bolts, n, low, pivot-1);
        match(nuts, bolts, n, pivot+1, high);

    }

}

void printA(char a[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%c", a[i]);
    }
}

int main() {
    char nuts[] = {'@', '#', '$', '%', '^', '&'};
    char bolts[] = {'$', '%', '&', '^', '@', '#'};
    match(nuts, bolts, 6, 0, 5);
    printf("Matched:\n");
    printA(nuts, 6);
    printA(bolts, 6);
}