#include "bits/stdc++.h"

template <typename T>
void print_vec(std::vector<T> vec) {
    for (const auto& x : vec) std::cout << x << " ";
    std::cout << "\n";
}


void solve(int n, std::vector<std::vector<int>> &adj) {
    std::vector<bool> visited(n, false);
    std::vector<int> prev(n, -1);

    // bfs (refer -> https://youtu.be/oDqjPvD54Ss)
    std::queue<int> processing;
    processing.push(1);
    visited[0] = true;

    while (!processing.empty()) {
        // while not finished processing
        // get the current unprocessed node
        int node = processing.front();

        // process the neighbors
        for (const auto &neighbor : adj[node-1]) {
            if (!visited[neighbor-1]) {
                visited[neighbor-1] = true;
                processing.push(neighbor);
                prev[neighbor-1] = node;
            }
        }

        // finished processing the neighbors
        processing.pop();
    }

    // reconstruct path
    int current_node = n;
    std::vector<int> path;

    while (current_node != -1) {
        path.push_back(current_node);
        current_node = prev[current_node-1];
    }

    std::reverse(path.begin(), path.end());
    if (path[0] == 1) {
        std::cout << path.size() << "\n";
        print_vec(path);
    } else {
        std::cout << "IMPOSSIBLE" << "\n";
    }
}


int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);

    while (m--) {
        int a, b;
        std::cin >> a >> b;
        adj[a-1].push_back(b);
        adj[b-1].push_back(a);
    }

    solve(n, adj);
}