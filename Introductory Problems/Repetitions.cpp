#include "bits/stdc++.h"

int main() {

    std::string s;
    std::cin >> s;

    int curr_max = 0;
    int curr_len = 0;
    char last_char = s[0];

    for (const auto &c : s) {

        if (last_char == c) {
            curr_len++;
            curr_max = std::max(curr_max, curr_len);
        } else {
            curr_len = 1;
            last_char = c;
        }

    }

    std::cout << curr_max << std::endl;
}