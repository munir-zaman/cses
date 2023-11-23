#include <bits/stdc++.h>
typedef long long ll;

int main() {
    ll n, x;
    std::cin >> n >> x;

    std::vector<ll> coins(n);
    for (int i = 0; i < n; i++) std::cin >> coins[i];

    std::vector<ll> dp(x+1, -1);
    dp[0] = 0;
    for (int k = 1; k <= x; k++) {
        ll optimal = (ll)1e6; // initially optimal = infinity
        for (ll &c : coins) {
            if ((k-c >= 0) && (dp[k-c] != -1)) {
                // update optimal
                optimal = std::min(optimal, dp[k-c]);
            }
        }
        if (optimal != (ll)1e6) dp[k] = 1 + optimal;
    }

    std::cout << dp[x] << "\n";
}