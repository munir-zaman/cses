#include "bits/stdc++.h"

int main()
{
    int n;
    std::cin >> n;

    if (n == 1)
    {
        std::cout << 1 << "\n";
    }
    else if (n <= 3)
    {
        std::cout << "NO SOLUTION"
                  << "\n";
    }
    else
    {
        int even_nums = 2;
        while (even_nums <= n)
        {
            std::cout << even_nums << " ";
            even_nums += 2;
        }

        int odd_nums = 1;
        while (odd_nums <= n)
        {
            std::cout << odd_nums << " ";
            odd_nums += 2;
        }
    }
}