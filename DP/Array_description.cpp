#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    // Initialize the dp table
    if (x[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }

    // Fill the dp table
    for (int i = 1; i < n; i++) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        } else {
            dp[i][x[i]] = dp[i-1][x[i]];
            if (x[i] > 1) dp[i][x[i]] = (dp[i][x[i]] + dp[i-1][x[i]-1]) % MOD;
            if (x[i] < m) dp[i][x[i]] = (dp[i][x[i]] + dp[i-1][x[i]+1]) % MOD;
        }
    }

    // Calculate the final answer
    int result = 0;
    for (int j = 1; j <= m; j++) {
        result = (result + dp[n-1][j]) % MOD;
    }

    cout << result << endl;

    return 0;
}
