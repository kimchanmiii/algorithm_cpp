#include <iostream>
#include <algorithm>
using namespace std;

int coin[101];
int dp[100001];
int main() {
	int testCase, n, m;
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        cin >> n;
        cin >> m;
        for (int i = 1; i <= m; i++) cin >> coin[i];
        fill(dp, dp+100001, 100001);
        dp[0] = 0;
        for (int i = 1; i <= m; i++){
            for (int j = coin[i]; j <= n; j++)
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
        dp[n] = (dp[n] == 100001) ? -1 : dp[n];
        cout << dp[n] << endl;
    }
	return 0;
}