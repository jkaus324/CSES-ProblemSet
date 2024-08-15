#include <iostream>
#include <vector>
#include <string>
using namespace std;

int editDistance(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    for (int i = 0; i <= n; i++) dp[i][0] = i;  // Deleting all characters in s1
    for (int j = 0; j <= m; j++) dp[0][j] = j;  // Inserting all characters in s2

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // No operation needed
            } else {
                dp[i][j] = min({dp[i - 1][j],    // Deletion
                                dp[i][j - 1],    // Insertion
                                dp[i - 1][j - 1] // Replacement
                               }) + 1;
            }
        }
    }
    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int result = editDistance(s1, s2);
    cout << result << endl;

    return 0;
}
