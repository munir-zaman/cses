#include <bits/stdc++.h>
#define ll long long

ll solve(ll x, ll y) {
    if (x == y) {
        // x == y => x(x-1) + 1
        return x * (x - 1) + 1;
    }

    ll z = std::max(x, y);
    if (z%2 == 0) {
        return solve(z, z) + y - x;
    } else {
        return solve(z, z) + x - y;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll x, y;
        std::cin >> y >> x;
        std::cout << solve(x, y) << "\n";
    }
}