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
    
    std::map<ll,std::map<ll,int>> table;

    ll ans = 0;
    for (int i = 0; i<n; i++) {
        if (i>0) table[i] = table[i-1];
        table[i][nums[i]]++;
    }

    for (int i = 0; i<n; i++) {

        std::cout << "index " << i << ": ";
        for (auto &x : table[i]) {
            std::cout << "{ " << x.first << ", " << x.second << " } ";
        }
        std::cout << " " << count_distincts(table[i]) << std::endl;
    }

    std::cout << std::endl;
}