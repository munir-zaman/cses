#include<bits/stdc++.h>

typedef long long ll;

int main() {
    ll n, x;
    std::cin >> n >> x;

    std::vector<ll> nums(n,0);
    for (auto &v : nums) std::cin >> v;

    std::map<ll, ll> sums;
    sums[0] = 1;

    ll ans = 0;
    ll current_sum = 0;
    for (auto &k : nums) {
        current_sum += k;
        ans += sums[current_sum - x];
        sums[current_sum]++;
    }

    std::cout << ans;
}