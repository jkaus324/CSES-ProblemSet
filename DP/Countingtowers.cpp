#include<iostream>
#include<vector>
using namespace std;

int MOD = 1e9+7;
vector<vector<int>> dp(1e6+1, vector<int>(2, 0));

int main() {
    int t;
    cin >> t;

    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i <= 1e6; i++) {
        dp[i][0] = (2LL * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (4LL * dp[i-1][1] + dp[i-1][0]) % MOD;
    }

    while(t--) {
        int n;
        cin >> n;
        n--;
        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }

    return 0;
}
