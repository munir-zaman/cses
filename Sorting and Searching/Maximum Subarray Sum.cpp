#include<bits/stdc++.h>
typedef long long ll;

int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> nums(n,0);
    for (auto &x : nums) std::cin >> x;

    std::vector<ll> prefix(n,0);
    prefix[0] = nums[0];
    for (int i = 1; i<n; i++) {
        prefix[i] = prefix[i-1] + nums[i];
    }
    ll last_min = 0;
    ll last_max_sum = -INT64_MAX;
    for (auto &x : prefix) {
        last_max_sum = std::max(last_max_sum, x - last_min);
        last_min = std::min(last_min, x);
    }

    std::cout << last_max_sum << "\n";
}