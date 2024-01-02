#include<bits/stdc++.h>
typedef long long ll;

int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> nums(n,0);
    for (auto &x : nums) std::cin >> x;

    std::vector<ll> prefix(n+1,0);
    prefix[0] = 0;
    for (int i = 1; i<=n; i++) {
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    for (auto &x : prefix) std::cout << x << ", ";
    std::cout << std::endl;
    ll MAX = *std::max_element(prefix.begin(), prefix.end());
    ll MIN = *std::min_element(prefix.begin(), prefix.end());
    std::cout << MAX - MIN << std::endl;
}