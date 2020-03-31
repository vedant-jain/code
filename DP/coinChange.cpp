#include<iostream>
  
using namespace std; 
  
int count( int coins[], int typesOfCoins, int target) 
{ 
    int x, y;
    int table[target + 1][typesOfCoins]; 

    for (int i = 0; i < typesOfCoins; i++) 
        table[0][i] = 1; 

    for (int i = 1; i < target + 1; i++) {
        for (int j = 0; j < typesOfCoins; j++) {
            // check for solutions with S[j]
            x = (i - coins[j] >= 0) ? table[i-coins[j]][j] : 0;
            // check for solutions without S[j]
            y = (j > 0) ? table[i][j-1] : 0;

            table[i][j] = x+y;
        }
    }

    return table[target][typesOfCoins-1];

} 
  
// Driver Code 
int main() 
{ 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4; 
    cout << count(arr, m, n) << "\n"; 
    return 0; 
} 