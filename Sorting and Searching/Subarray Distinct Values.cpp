#include<bits/stdc++.h>
typedef long long ll;

int count_distincts(std::map<ll,int> N) {
    int ans = 0;
    for (auto &x : N) {
        if (x.second > 0) ans++;
    }
    return ans;
}


int main() {
    ll n, k;
    std::cin >> n >> k;

    std::vector<ll> nums(n,0);
    for(auto &v : nums) std::cin >> v;
    
    std::vector<ll> repeats;
    ll last_num = nums[0];
    ll counter = 0;
    for (int i = 0; i<n; i++) {
        if (last_num == nums[i]) counter++;
        else {
            repeats.push_back(counter);
            counter = 1;
        }
        last_num = nums[i];
    }

    repeats.push_back(counter);

    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < repeats.size(); i++) {
        if (i-k>=0) sum = sum - repeats[i-k];
        ans += (1 << repeats[i]) - 1 + repeats[i]*sum;
        sum = sum + repeats[i];
    }
    std::cout << ans << "\n";
}