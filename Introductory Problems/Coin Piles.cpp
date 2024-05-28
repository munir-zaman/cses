#include<bits/stdc++.h>
#define ll long long

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b;
        std::cin >> a >> b;

        int x = a - (a+b)/3;
        int y = b - (a+b)/3;
        if (x>=0 && y>=0 && ((a+b)%3==0)) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}