#include <bits/stdc++.h>
#define ll long long
// size of bit string k < 30
#define K_MAX 30

int hamming(const std::bitset<K_MAX> &x, const std::bitset<K_MAX> &y) {
    // calculates the hamming distance between x and y
    std::bitset<K_MAX> z = x ^ y;
    return z.count();
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::bitset<K_MAX>> bits(n);
    for (int i=0; i<n; i++) std::cin >> bits[i];

    // brute force?
    int min_hamming = K_MAX;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            min_hamming = std::min(hamming(bits[i], bits[j]), min_hamming);
        }
    }
    std::cout << min_hamming << std::endl;
}