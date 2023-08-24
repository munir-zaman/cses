#include "bits/stdc++.h"

int main()
{

    int n;
    std::cin >> n;

    std::vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    long long counter = 0;
    for (int k = 1; k < n; k++)
    {
        if (nums[k] < nums[k - 1])
        {
            counter += nums[k - 1] - nums[k];
            nums[k] = nums[k - 1];
        }
    }

    std::cout << counter << "\n";
}