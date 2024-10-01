#include <bits/stdc++.h>
#define ll long long

ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  return x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    ll x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll a = area(x1, y1, x2, y2, x3, y3);

    if (a == 0)
      printf("TOUCH\n");
    else if (a > 0)
      printf("LEFT\n");
    else
      printf("RIGHT\n");
  }
}