#include <iostream>
#include <cstring>
#include <climits>

#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        int dp[101][101] = { 0, };
        int n;
        int num[101];
        cin >> n;
        for (int i = 0; i < n+1; i++) { cin >> num[i]; }
        for (int i = 0; i < n + 1; i++) {
            for (int j = 1; j+i < n + 1; j++) {
                dp[j][j + i] = INT_MAX;
                if (i == 0)
                    dp[j][j + i] = 0;

                for (int k = j; k <= i + j - 1;k++) {
                    int temp = dp[j][k] + dp[k + 1][j + i] + num[j - 1] * num[k]* num[i + j];
                    if (temp < dp[j][j + i]) { dp[j][j + i] = temp; }
                }
            }
        }
        cout << dp[1][n] << endl;
    }
}