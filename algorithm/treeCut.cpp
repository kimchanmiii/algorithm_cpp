#include <iostream>

#define INF 987654321

using namespace std;

int dp[500][500];

int main() {
    int t; cin >> t;
    while(t--) {
        int c[500];
        int k; cin >> k;
        for(int i=0; i<k; i++)
            cin >> c[i];
        
        for(int i=1; i<k; i++)
            for(int j=0; j<k-i; j++) {
                dp[j][j+i] = INF;
                int s = 0; for(int k=j; k<=j+i; k++) s += c[k];
                for(int k=j; k<j+i; k++) {
                    int tmp = s + dp[j][k] + dp[k+1][j+i];
                    if(dp[j][j+i] > tmp) dp[j][j+i] = tmp;
                }
            }

        cout << dp[0][k-1] << '\n';
    }

    return 0;
}