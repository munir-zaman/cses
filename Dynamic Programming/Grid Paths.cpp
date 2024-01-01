#include <bits/stdc++.h>
typedef long long ll;

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<bool>> grid(n, std::vector<bool>(n, true));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char state;
            std::cin >> state;
            if (state == '*') grid[i][j] = false;
        }
    }

    ll M = 1e9 + 7;
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, 0));
    if (grid[n-1][n-1]) dp[0][0] = 1;
    // dp[0][0] is the lower right corner
    // dp[i][j] = dp[i-1][j] + dp[i][j-1]

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[n-i-1][n-j-1]) {
                if (i-1 >= 0) dp[i][j] += dp[i-1][j]%M;
                if (j-1 >= 0) dp[i][j] += dp[i][j-1]%M;
                dp[i][j] = dp[i][j]%M;
            }
        }
    }

    std::cout << dp[n-1][n-1] << "\n";
}