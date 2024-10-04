#include <bits/stdc++.h>
#define ll long long

// TODO: GOTTA DEAL WITH EDGE CASES :3

ll signed_area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ll f1 = signed_area(x1, y1, x3, y3, x2, y2);
    ll f2 = signed_area(x1, y1, x4, y4, x2, y2);
    ll f3 = signed_area(x3, y3, x1, y1, x4, y4);
    ll f4 = signed_area(x3, y3, x2, y2, x4, y4);

    if (f1 * f2 < 0 && f3 * f4 < 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
}

// FAILS ON SOME TESTCASES