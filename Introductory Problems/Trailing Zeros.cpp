#include <bits/stdc++.h>
typedef long long ll;

ll padic(ll n, ll p) {
    ll prod = p;
    ll term = n / prod;
    ll sum = 0;

    while (term != 0) {
        sum += term;
        prod *= p;
        term = n / prod;
    }

    return sum;
}

int main() {
    ll n;
    std::cin >> n;
    std::cout << padic(n, 5);
}