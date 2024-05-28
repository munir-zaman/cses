#include<bits/stdc++.h>
#define ll long long

int main() {
    ll n;
    std::cin >> n;

    for (ll k=1; k<=n; k++) {
        ll x = (k*k)*(k*k-1)/2;
        if (x>3) x -= 4*(k-2)*(k-1);
        std::cout << x << "\n";
    }
}