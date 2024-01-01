#include<bits/stdc++.h>
typedef long long ll;

int main(){
    int n, x;
    std::cin >> n >> x;

    std::vector<int> price(n);
    std::vector<int> pages(n);

    for (int i = 0; i < n; i++) std::cin >> price[i];   
    for (int i = 0; i < n; i++) std::cin >> pages[i];

    std::map<int,int> table;
    for (int i = 0; i < n; i++) table.insert(std::pair<int,int>(price[i], pages[i]));

    std::vector<int> dp(x+1, 0);
    for (int k = 1; k <= x+1; k++) {
        for (int j = 0; j < n; j++) {
            if (k-price[j] >= 0) dp[k] = std::max(dp[k], pages[j] + dp[k-price[j]]);
        }
    }

    std::cout << dp[x+1] << "\n"; 
}