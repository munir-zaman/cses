#include "bits/stdc++.h"

template <typename T>
void print_vec(std::vector<T> vec)
{
    for (const auto &x : vec)
        std::cout << x << " ";
    std::cout << "\n";
}

void dfs(int a, std::vector<std::vector<int>> &adj, std::vector<bool> &visited)
{
    visited[a - 1] = true;
    for (const auto &neighbor : adj[a - 1])
    {
        if (!visited[neighbor - 1])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

int count_components(std::vector<std::vector<int>> &adj, int n)
{
    std::vector<bool> visited(n, false);

    int components = 0;
    for (int node = 1; node <= n; node++)
    {
        if (!visited[node - 1])
        {
            components++;
            dfs(node, adj, visited);
        }
    }

    return components;
}

void solve(std::vector<std::vector<int>> &adj, int n)
{
    std::vector<bool> visited(n, false);

    std::vector<int> roads;

    int components = 0;
    for (int node = 1; node <= n; node++)
    {
        if (!visited[node - 1])
        {
            roads.push_back(node);
            components++;
            dfs(node, adj, visited);
        }
    }

    std::cout << components - 1 << "\n";
    for (int i = 1; i < components; i++)
    {
        std::cout << roads[0] << " " << roads[i] << "\n";
    }
}

int main()
{
    int n, m; // cities, roads
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);

    while (m--)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a - 1].push_back(b);
        adj[b - 1].push_back(a);
    }

    solve(adj, n);
}