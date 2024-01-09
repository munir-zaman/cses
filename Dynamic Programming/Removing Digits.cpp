#include<bits/stdc++.h>
typedef long long ll;

int main() {
    ll n;
    std::cin >> n;

    std::vector<ll> dps(n+1, INT64_MAX);
    dps[0] = 0;
    for (int N = 1; N<=n; N++) {
        ll x = N;
        while (x!=0) {
            ll d = x%10;
            x = x/10;
            if (N-d>=0 && d!=0) dps[N] = std::min(dps[N], 1+dps[N-d]);
        }
    }

    std::cout << dps[n] << std::endl;
}