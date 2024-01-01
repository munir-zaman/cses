#include "bits/stdc++.h"

// NOTE: have to properly rewrite the solution (it works btw! :D)

void update(int n, std::map<int, std::vector<int>> &children, std::vector<int> &descendants) {
    descendants[n-1] = 0; // has been processed
    for (auto &child : children[n]) {
        // update descendants for children not yet processed
        if (descendants[child-1] == -1) { update(child, children, descendants); }
    }
    for (auto &child : children[n]) {
        // update descendants for current node n
        descendants[n-1] += descendants[child-1] + 1;
    }
}


int main() {
    int n;
    std::cin >> n;

    // <child, parent> map
    std::map<int, int> parents;
    for (int i = 1; i <= n; i++) { parents[i] = 0; }
    
    // <parent, children> map
    std::map<int, std::vector<int>> children;
    for (int i = 1; i <= n; i++) { children[i] = {}; }

    for (int i = 1; i < n; i++) {
        int p; // parent of i+1
        std::cin >> p;

        parents[i+1] = p;
        children[p].push_back(i+1);

    }

    std::vector<int> descendants(n, -1);
    // update descendants
    update(1, children, descendants);
    
    // print out descendants
    for (auto &x : descendants) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}