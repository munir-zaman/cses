#include <bits/stdc++.h>
typedef long long ll;

int main() {
    ll n;
    std::cin >> n;

    std::vector<ll> dp(n+1);
    dp[0] = 1;
    // sum of last 6 elements
    ll M = 1e9 + 7;
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i-j >= 0) dp[i] = (dp[i-j] + dp[i])%M;
        }
    }

    std::cout << dp[n] << "\n";
}