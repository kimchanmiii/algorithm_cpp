#include <iostream>
#include <string.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int dp[501][501];
int divide[501];
int s[501];
int testCase, l, k;
int divide_n[501];
int main() {
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        cin >> l >> k;
        for (int i = 1; i <= k; i++) { cin >> divide[i]; }
        for (int i = 1; i <= k+1; i++) {
            if (i == 1)
                divide_n[1] = divide[1];
            else if (i == k+1)
                divide_n[i] = l-divide[i-1];
            else
                divide_n[i] = divide[i] - divide[i - 1];
        }
        for (int i = 1; i <= k+1; i++) { s[i] = s[i - 1] + divide_n[i]; }


        for (int i = 1; i < k+1; i++) {
            for (int j = 1; j + i <= k+1; j++) {
                int p = j + i;
                dp[j][p] = INT_MAX;
                for (int mid = j; mid < p; mid++)
                    dp[j][p] = min(dp[j][p], dp[j][mid] + dp[mid + 1][p] + s[p] - s[j - 1]);
            }
        }
        cout << dp[1][k+1] << endl;
    }
    return 0;
}