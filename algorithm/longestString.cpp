#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    for (int t = 0; t < testCase; t++)
    {
        char input1[101];
        char input2[101];
        int dp[101][101];
        cin >> input1;
        cin >> input2;

        for (int i = 0; i <= strlen(input1); i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= strlen(input2); i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= strlen(input1); i++) {
            for (int j = 1; j <= strlen(input2); j++) {
                if (input1[i-1] == input2[j-1]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << dp[strlen(input1)][strlen(input2)] << endl;  
    }
}