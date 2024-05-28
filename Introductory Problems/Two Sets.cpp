#include<bits/stdc++.h>
#define ll long long

int main() {
    int n;
    std::cin >> n;

    if ((n%4==0) || (n%4==3)) std::cout << "YES\n";
    else std::cout << "NO\n";

    if (n%4==0) {
        
        std::cout << n/2 << "\n";
        for (int i=1; i<=n/2; i+=2) std::cout << i << " " << n+1-i << " ";
        std::cout << "\n";

        std::cout << n/2 << "\n";
        for (int i=2; i<=n/2; i+=2) std::cout << i << " " << n+1-i << " ";

    }

    else if (n%4==3) {

        std::cout << n/2+1 << "\n";
        std::cout << 1 << " " << n-1 << " ";
        for (int i=2; i<=(n/2); i+=2) std::cout << i << " " << n-i << " ";
        std::cout << "\n";

        std::cout << n/2 << "\n";
        std::cout << n << " ";
        for (int i=3; i<=(n/2); i+=2) std::cout << i << " " << n-i << " ";

    }

}