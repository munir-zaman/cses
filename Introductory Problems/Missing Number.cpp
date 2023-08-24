#include "bits/stdc++.h"

int main()
{

    int n;
    std::cin >> n;

    std::vector<int> nums(n - 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> nums[i];
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;

    int our_sum = 0;
    for (int i = 0; i < n - 1; i++)
        our_sum += nums[i];

    std::cout << sum - our_sum << std::endl;
}