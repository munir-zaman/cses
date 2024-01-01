#include<bits/stdc++.h>

typedef long long ll;

int main() {
    ll n;
    std::cin >> n;

    std::vector<ll> nums(n,0);
    for (auto &v : nums) std::cin >> v;

    std::map<ll, ll> mod_table;

    ll ans = 0;
    ll current_sum = 0;
    for (auto &k : nums) {
        current_sum += (k%n + n)%n;
        // taking the positive modulo -> (k%n + n)%n
        // negative mod messes up our dictionary ("sums")
        if (current_sum%n == 0) ans++;
        ans += mod_table[current_sum%n];
        mod_table[current_sum%n]++;
    }
    std::cout << ans;
}