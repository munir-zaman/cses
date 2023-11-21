#include <bits/stdc++.h>
#define ll long long

int main() {
    ll n; std::cin >> n;

    ll s = 1;
    while (n--) {
        s = 2*s%((ll)1e9+7);
    }

    std::cout << s;
}