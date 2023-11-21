#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    int counter = 1;
    int last = nums[0];

    for (int i = 0; i < n; i++) {
        if (last != nums[i]) {
            counter++;
            last = nums[i];
        }
    }

    std::cout << counter << "\n";
}