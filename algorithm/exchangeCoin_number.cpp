#include <iostream>
using namespace std;

#define MAX_COINS 101
#define MAX_CHANGE 1001

int main() {
    int testCase;
    cin >> testCase; 

    for (int t = 0; t < testCase; t++) {
        int i, j, numComb;
        int N[MAX_COINS][MAX_CHANGE] = {0};
        int numDiffCoins, change;
        
        cin >> change;
        cin >> numDiffCoins;
        
        int coins[numDiffCoins+1];

        for (i = 1; i <= numDiffCoins; i++) cin >> coins[i];

        for (i = 1; i <= numDiffCoins; i++) {
            N[i][0] = 1;
        }
        for (i = 1; i <= change; i++) {
            N[0][i] = 0;
        }
        for (i = 1; i <= numDiffCoins; i++) {
            for (j = 1; j <= change; j++) {
                if (j-coins[i] < 0) numComb = 0;
                else numComb = N[i][j-coins[i]];
                N[i][j] = N[i-1][j] + numComb;
            }
        }
        cout << N[numDiffCoins][change] << endl;
    }
}