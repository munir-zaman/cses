#include <bits/stdc++.h>
#define ll long long

int main() {
  int n;
  std::cin >> n;

  std::vector<ll> x(n + 1);
  std::vector<ll> y(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  x[n] = x[0];
  y[n] = y[0];

  ll A = 0; // 2*area (signed)
  for (int i = 0; i < n; i++)
    A += x[i] * y[i + 1] - x[i + 1] * y[i];
  // take absolute value
  A = A >= 0 ? A : -A;
  std::cout << A << std::endl;
}