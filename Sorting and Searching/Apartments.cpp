#include <bits/stdc++.h>
// TODO
int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> applicants(n);
    std::vector<int> apartments(m);

    for (int i = 0; i < n; i++) std::cin >> applicants[i];
    for (int i = 0; i < m; i++) std::cin >> apartments[i];

    std::sort(applicants.begin(), applicants.end());

    int counter = 0;
    int index = 0;

    for (int i = 0; i < m; i++) {
        int apart_size = apartments[i];
        for (int j = index; j < n; j++) {
            if (apart_size - k <= applicants[j] && applicants[j] <= apart_size + k) {
                std::cout << applicants[j] << " -> " << apart_size << "\n";
            }

        }
    }
}