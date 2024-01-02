#include<bits/stdc++.h>
typedef long long ll;

int main() {
    ll n, k;
    std::cin >> n >> k;

    std::vector<ll> nums(n,0);
    for(auto &v : nums) std::cin >> v;

    ll counter = 0;
    ll last_num = nums[0];
    std::queue<ll> repeat_start;
    std::map<ll, bool> seen;

    ll ans = 0;
    for (int i = 0; i<n; i++) {
        if (last_num != nums[i]) {
            if (!seen[nums[i]]) {
                // increase counter if encountered a new value not seen before
                counter++;
                seen[nums[i]] = true;
            }
            repeat_start.push(nums[i]);
        }

        if (counter>k) {
            counter--;
            seen[nums[i]] = false;
        }
        
        ans += i - repeat_start.front() + 1;
        // update last_num
        last_num = nums[i];
    }
}